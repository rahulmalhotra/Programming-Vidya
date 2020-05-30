/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RECNDSTR Problem
*   Problem Link:- https://www.codechef.com/problems/RECNDSTR
*/
#include <iostream>
#include<cstring>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, i;
    char s[1000005], leftShift[1000005], rightShift[1000005];

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting string for each test case
        cin>>s;

        // * Calculating length of string
        int length = strlen(s);

        /*
        *   Looping the characters of the string (starting with index 1)
        *   to create left-shift and right-shift strings
        */
        for(i=1; i<length; i++) {

            /*
            *   Current character of original string
            *   will be at previous position in left-shift string
            */
            leftShift[i-1] = s[i];

            /*
            *   Current character in right-shift string will be
            *   the previous character of original string
            */
            rightShift[i] = s[i-1];
        }

        // * Last character of left-shift string = First character of original string
        leftShift[i-1] = s[0];

        // * First character of right-shift string = Last character of original string
        rightShift[0] = s[i-1];

        /*
        *   Setting the next character occuring after original
        *   left-shifted string to null
        */
        leftShift[i] = '\0';

        /*
        *   Setting the next character occuring after original
        *   right-shifted string to null
        */
        rightShift[i] = '\0';

        /*
        *   If the left-shift and right-shift strings are equal,
        *   this means that we can find a string whose
        *   left-shift and right-shift versions are equal to original string
        */
        if(strcmp(leftShift, rightShift) == 0) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}