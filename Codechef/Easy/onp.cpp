/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ONP Problem
*   Problem Link:- https://www.codechef.com/problems/ONP
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

/*
*   This method is used to find the Reverse Polish Notation
*   of the expression stored in string s
*/
void rpn(string s) {

    // * Calculating the length of the string
    int length = s.length();

    // * Initializing the stack
    stack<char> st;

    // * Evaluating each character of the string
    for(int i=0; i<length; i++) {

        /*
        *   If the character is an operator or opening bracket (,
        *   push it into the stack
        */
        if(
            s[i]=='(' ||
            s[i]=='+' ||
            s[i]=='-' ||
            s[i]=='*' ||
            s[i]=='/' ||
            s[i]=='^'
        ) {
            st.push(s[i]);
        }

        // * If the character is a closing bracket
        else if(s[i]==')') {

            /*
            *   Pop all the operators out of the stack and display those
            *   until you encounter the opening bracket (
            */
            while(st.top()!='(') {
                cout<<st.top();
                st.pop();
            }

            // * Pop the opening bracket as well before considering the next character
            st.pop();
        }

        // * Otherwise, display the character
        else {
            cout<<s[i];
        }
    }
}

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Declaring the variables
    int numberOfTestCases;
    string expression;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the expression for the current test case
        cin>>expression;

        /*
        *   Calculating and displaying the Reverse Polish Notation
        *   of the current expression
        */
        rpn(expression);

        // * Adding a new line before executing the next test case
        cout<<endl;
    }
}