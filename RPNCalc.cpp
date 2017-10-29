//
//  RPNCalc.cpp
//  comp15hw3
//
//  Created by Vincent Bett on 9/26/16.
//  Implementation of the RPN calculator
//

#include "RPNCalc.h"


// Constructor
RPNCalc::RPNCalc()
{

}

// Destructor
RPNCalc::~RPNCalc()
{

}



/*
Function:       Run.
Purpose:        function that takes no parameters.  This function will
                launch a process  like dc's command loop, reading in commands
                from the standard input (cin).
Input:          None
Output:         None
*/
void RPNCalc::run()
{

        while(1)
        {

                string input;
                cin >> input;

                performCalculations(input);
        }
}


/*
Function:       Add.
Purpose:        To add two numbers in the stack
Input:          None
Output:         None
*/
void RPNCalc::add()
{
        double first, second, ans;
        first = calc.pop();
        second = calc.pop();
        ans = first + second;
        calc.push(ans);

}

/*
Function:       Subtract.
Purpose:        To Subtract two numbers in the stack
Input:          None
Output:         None
*/
void RPNCalc::subtract()
{
        double first, second, ans;
        first = calc.pop();
        second = calc.pop();
        ans = first - second;
        calc.push(ans);
}



/*
Function:       multiply.
Purpose:        To multiply two numbers in the stack.
Input:          None
Output:         None.
*/
void RPNCalc::multiply()
{
        double first, second, ans;
        first = calc.pop();
        second = calc.pop();
        ans = first * second;
        calc.push(ans);
}

/*
Function:       Divide.
Purpose:        To divide two numbers in the stack.
Input:          None
Output:         None
*/
void RPNCalc::divide()
{
        double first, second, ans;
        first = calc.pop();
        second = calc.pop();
        ans = first / second;
        calc.push(ans);
}

/*
Function:       Print
Purpose:        To print the top value of the stack
Input:          None
Output:         None
*/
void RPNCalc::print()
{
        cout<<calc.top()<<endl;
}

/*
Function:       Clear.
Purpose:        Delete the elements in the stack
Input:          None
Output:         None.
*/
void RPNCalc::clear()
{
        calc.clear();
}

/*
Function:       GotDouble
Purpose:        To check if a string is a double
Input:          a string and a pointer to a double
Output:         Returns true is it's a double or otherwise
*/
bool RPNCalc::gotDouble(string s, double *resultp)
{
        return sscanf(s.c_str(), "%lf", resultp) == 1;
}


/*
Function:       readFile
Purpose:        To read the contents of a file
Input:          a String
Output:         None
*/
void RPNCalc::readFile(string s)
{
        ifstream input;

        input.open(s.c_str());
        if (not input.is_open()) {
                cerr << "Unable to open " << s << endl;

        }
        copy_strings_from(input);
        input.close();

        //copy_from_cin(cin);

}
/*
Function:       Copy_string_from
Purpose:        To copy the contents of a file
Input:          A pointer to afile location
Output:         None
*/
void RPNCalc::copy_strings_from(istream &infile)
{
        string s;
        for (infile >> s; not infile.eof(); infile >> s)
        {
                // If there's a second file in the opened file.
                if(s == "f")
                {
                        string filename;
                        infile >> filename;
                        readFile(filename);
                }
                performCalculations(s);
        }

}


/*
Function:       Perform calcultaions
Purpose:        To do the calculation on the elements in a stack
Input:          a String
Output:         None.
*/
void RPNCalc::performCalculations(string input)
{
        double value;
        bool isDouble = false;
        isDouble = gotDouble(input, &value);


        if(isDouble)
        {
                calc.push(value);

        }
        else if(input == "+")
        {
                add();

        }
        else if(input == "-")
        {
                subtract();
        }
        else if (input == "/")
        {
                divide();
        }
        else if(input == "c" or input == "C")
        {
                clear();
        }
        else if(input == "f" or input == "F")
        {
                string filename;
                cin >> filename;
                readFile(filename);

        }
        else if (input =="p" or input == "P")
        {
                print();
        }

        else if(input == "q" or input == "Q")
                exit(0);
        else{
                cerr<< input <<": unimplemented"<<endl;
        }


}
