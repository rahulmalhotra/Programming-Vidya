/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MATCHES Problem
*   Problem Link:- https://www.codechef.com/problems/MATCHES
*/
#include <iostream>
using namespace std;
int main() {

    /*
    *   Initializing variables
    *   matchesArr specify of the number of matches needed for each digit
    *   from 0 to 9 based on the array index
    */
    int numberOfTestCases, a, b, c,
    matchesArr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, lastDigit, numberOfMatches = 0;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting integers a and b
        cin>>a>>b;

        // * Calculating the sum of a and b and storing in c
        c = a + b;

        // * Looping while c is not zero
        while(c!=0) {

            // * Extracting the last digit from c
            lastDigit = c % 10;

            // * Adding the matches needed for last digit in number of matches variable
            numberOfMatches += matchesArr[lastDigit];

            // * Removing the last digit from integer c
            c = c / 10;
        }

        // * Displaying number of matches required for current test case
        cout<<numberOfMatches<<endl;

        // * Resetting number of matches to 0 for next upcoming test case
        numberOfMatches = 0;
    }
}