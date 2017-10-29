//
//  DoubleStack.cpp
//  comp15hw3
//
//  Created by Vincent Bett on 9/26/16.
//  An implementation of A Stack class that holds doubles.
//

#include "DoubleStack.h"

/*
The default constructor takes no parameters and initializes an
empty stack.
*/
DoubleStack::DoubleStack()
{

        capacity = CAPACITY;
        stack =  new double[capacity];
        topStk = -1;

}

/*
takes an array of doubles and an
integer specifying the size of the array as parameters and
creates a stack initialized so that the elements of the array
are on the stack with the array's element 0 pushed on first
and it's (size - 1)st element at the top of the stack.
*/
DoubleStack::DoubleStack(double arr[], int n)
{
        capacity = CAPACITY;
        stack = new double[capacity];
        topStk = -1;

        for(int i = 0; i < n; i++)
        {
                if(i == capacity-1)
                {
                        expand();
                }
                stack[i] = arr[i];
                topStk++;
        }
}

// Destructor
DoubleStack::~DoubleStack()
{
        delete[] stack;
}

/*
Function:       isempty
Purpose:        function that takes no parameters and returns a
                boolean value that is true if this specific instance of the
                DoubleStack class is empty and false otherwise.
Input:          None
Output:         None
*/

bool DoubleStack::isEmpty()
{
        return topStk == -1;
        
}

/*
Function:       Clear
Purpose:        function that takes no parameters and has a void
                return type.It makes the current stack into an empty stack.
Input:          none
Output          None
*/

void DoubleStack::clear()
{
        topStk = -1;
        delete [] stack;
}

/*
Function:       size
Purpose:        function that takes no parameters and returns an
                integer value that is the number of doubles on the stack.
Input:          None
Output:         An int.
*/
int DoubleStack::size()
{
        return topStk + 1;
}

/*
Function:       Top
Purpose:        function that takes no parameters and returns the top
                element (double) on the stack.  If the stack is empty it throws
                a C++ "runtime_error" exception with the message "empty_stack".
Input:          None
Output:         a double
*/

double DoubleStack::top()
{
        if(topStk == -1)
        {
                throw string("empty_stack");
        }
        return stack[topStk];
}

/*
Function:       pop
Purpose:        function that takes no parameters. It removes and
                returns the first element (double) on the stack.  If the stack
                is empty it throws a C++ "runtime_error" exception with the
                message "empty_stack".
Input:          None
Output:         None
*/

double DoubleStack::pop()
{
        if (topStk == -1)
                throw string("empty_stack");

        double TopElement = stack[topStk];
        DecrementStack();
        return TopElement;
}

// Keep track as the stack is reduced.
void DoubleStack::DecrementStack()
{
        topStk--;
}

/*
Function:       Push
Purpose:        function that takes an element (double) and puts it
                on the top of the stack.
Input:          a double
Output:         None
*/

void DoubleStack::push(double elem)
{

        if(topStk == capacity - 1  )
        {

                expand();
        }

        stack[topStk+1] = elem;
        incrementStack();

}

// Keep track of the top element.
void DoubleStack::incrementStack()
{
        topStk++;
}

void DoubleStack::expand()
{
        double *newArray;
        newArray = new double[capacity*2];
        for(int i = 0; i<capacity; i++)
        {
                newArray[i] = stack[i];
        }
        delete[] stack;
        stack = newArray;
        capacity*=2;

}

int DoubleStack::getTop()
{
        return topStk;
}




