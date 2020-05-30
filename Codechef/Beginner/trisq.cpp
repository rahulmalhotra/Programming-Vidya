/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TRISQ Problem
*   Problem Link:- https://www.codechef.com/problems/TRISQ
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, base, numberOfSquares;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing the number of squares to 0 for current test case
        numberOfSquares = 0;

        // * Accepting the base of the triangle
        cin>>base;

        /*
        *   Calculating the number of squares at each level in a triangle
        *   and adding it to the total number of squares
        *   After calculating for one level,
        *   the base is reduced by 2 for the next upper level
        *   Base should be greater than 2 to have at least one square of side 2
        */
        while(base>2) {
            numberOfSquares += (base-2)/2;
            base -= 2;
        }

        // * Displaying the number of squares for the current test case
        cout<<numberOfSquares<<endl;
    }
}