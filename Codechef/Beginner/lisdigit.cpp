/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef LISDIGIT Problem
*   Problem Link:- https://www.codechef.com/problems/LISDIGIT
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, numberOfDigits, digit;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of digits in LIS array for the current test case
        cin>>numberOfDigits;

        // * Accepting each digit of LIS array one by one and printing that
        for(int i=0; i<numberOfDigits; i++) {
            cin>>digit;
            cout<<digit;
        }

        // * Displaying a new line before considering the next test case
        cout<<endl;
    }
}