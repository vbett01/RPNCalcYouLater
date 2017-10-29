//
//  DoubleStack.hpp
//  comp15hw3
//
//  Created by Vincent Bett on 9/26/16.
//  Header file for a stack that holds doubles
//

#ifndef DoubleStack_h
#define DoubleStack_h

#include <stdio.h>
#include <iostream>
using namespace std;
const int CAPACITY = 10;


class DoubleStack
{
        public:
/*
The default constructor takes no parameters and initializes an
empty stack.
*/
                DoubleStack();

/*
takes an array of doubles and an
integer specifying the size of the array as parameters and
creates a stack initialized so that the elements of the array
are on the stack with the array's element 0 pushed on first
and it's (size - 1)st element at the top of the stack.
*/
                DoubleStack(double arr[], int n);

                // Destructor.
                ~DoubleStack();

/*
Function:       isempty
Purpose:        function that takes no parameters and returns a
                boolean value that is true if this specific instance of the
                DoubleStack class is empty and false otherwise.
Input:          None
Output:         None
*/
                bool isEmpty();

                /*
Function:       Clear
Purpose:        function that takes no parameters and has a void
                return type. It makes the current stack into an empty stack.
Input:          none
Output          None
*/
                void clear();

/*
Function:       size
Purpose:        function that takes no parameters and returns an
                integer value that is the number of doubles on the stack.
Input:          None
Output:         None
*/
                int size();

/*
Function:       Top
Purpose:        function that takes no parameters and returns the top
                element (double) on the stack.  If the stack is empty it throws
                a C++ "runtime_error" exception with the message "empty_stack".
Input:          None
Output:         a double
*/

                double top();

/*
Function:       pop
Purpose:        function that takes no parameters. It removes and
                returns the first element (double) on the stack.  If the stack
                is empty it throws a C++ "runtime_error" exception with the
                message "empty_stack".
Input:          None
Output:         None
*/
                double pop();

/*
Function:       Push
Purpose:        function that takes an element (double) and puts it
                on the top of the stack.
Input:          a double
Output:         None
*/
                void push(double elem);

        private:
                // Pointer to a double
                double *stack;
                //initial capacity
                int capacity;
                // Grow the stack
                void expand();
                //Location of the top element
                int topStk;
                // Keep track as the stack is reduced.
                void DecrementStack();
                // Keep track of the top element.

                void incrementStack();
                int getTop();

};

#endif /* DoubleStack_hpp */
