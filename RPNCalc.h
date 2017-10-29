//
//  RPNCalc.hpp
//  comp15hw3
//
//  Created by Vincent Bett on 9/26/16.
//  Header file for an RPN calculator.
//

#ifndef RPNCalc_h
#define RPNCalc_h

#include <stdio.h>
#include "DoubleStack.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class RPNCalc
{
        public:

/*
Constructor.
*/
                RPNCalc();

//Destructor.
                ~RPNCalc();

/*
Function:       Run.
Purpose:        function that takes no parameters.  This function will
                launch a process  like dc's command loop, reading in commands
                from the standard input (cin).
Input:          None
Output:         None
*/
                void run();
        private:

/*
Function:       Add.
Purpose:        To add two numbers in the stack
Input:          None
Output:         None
*/
                void add();

/*
Function:       Subtract.
Purpose:        To Subtract two numbers in the stack
Input:          None
Output:         None
*/
                void subtract();

/*
Function:       multiply.
Purpose:        To multiply two numbers in the stack.
Input:          None
Output:         None.
*/
                void multiply();
/*
Function:       Divide.
Purpose:        To divide two numbers in the stack.
Input:          None
Output:         None
*/
                void divide();
/*
Function:       Print
Purpose:        To print the top value of the stack
Input:          None
Output:         None
*/
                void print();
/*
Function:       Clear.
Purpose:        Delete the elements in the stack
Input:          None
Output:         None.
*/

                void clear();
/*
Function:       GotDouble
Purpose:        To check if a string is a double
Input:          a string and a pointer to a double
Output:         Returns true is it's a double or otherwise
*/
                bool gotDouble(string s, double *resultp);
/*
Function:       readFile
Purpose:        To read the contents of a file
Input:          a String
Output:         None
*/
                void readFile(string s);

/*
Function:       Copy_string_from
Purpose:        To copy the contents of a file
Input:          A pointer to afile location
Output:         None
*/
                void copy_strings_from(istream &infile);
/*
Function:       Perform calcultaions
Purpose:        To do the calculation on the elements in a stack
Input:          a String
Output:         None.
*/
                void performCalculations(string s);
                DoubleStack calc;
};

#endif /* RPNCalc_hpp */
