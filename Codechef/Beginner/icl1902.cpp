/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ICL1902 Problem
*   Problem Link:- https://www.codechef.com/problems/ICL1902
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, n, numberOfSquares = 0, sideOfSquare;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting integer n
        cin>>n;

        // * Looping while n is greater than 0
        while(n>0) {

            // * Finding the side whose square is less than n
            for(sideOfSquare=1; sideOfSquare*sideOfSquare<=n; sideOfSquare++);
            sideOfSquare--;

            // * Incrementing the number of squares by 1
            numberOfSquares++;

            /*
            *   Updating n by subtracting the number of circles
            *   already used in previous square
            */
            n = n - sideOfSquare*sideOfSquare;
        }

        // * Displaying the number of squares for current test case
        cout<<numberOfSquares<<endl;

        // * Resetting the number of squares to zero for next upcoming test case
        numberOfSquares =  0;
    }
}