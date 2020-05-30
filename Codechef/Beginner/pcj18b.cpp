/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PCJ18B Problem
*   Problem Link:- https://www.codechef.com/problems/PCJ18B
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, sizeOfChessBoard, numberOfSquaresWithOddLength = 0, start = 0;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting size of chess board for each test case
        cin>>sizeOfChessBoard;

        /*
        *   Checking if the size of chess board is odd or not
        *   using bitwise operators, if the size is odd,
        *   start element will be 1 otherwise 2
        */
        if(sizeOfChessBoard & 1) {
            start = 1;
        } else {
            start = 2;
        }

        /*
        *   Running loop from start element and adding 2 after each
        *   iteration to the loop counter variable and adding the square
        *   of loop counter variable to total count (number of squares with odd length)
        */
        for(int i=start; i<=sizeOfChessBoard; i+=2) {
            numberOfSquaresWithOddLength += i*i;
        }

        // * Displaying the number of squares with odd length for current test case
        cout<<numberOfSquaresWithOddLength<<endl;

        /*
        *   Resetting the number of squares with odd length variable to 0
        *   for next upcoming test case
        */
        numberOfSquaresWithOddLength = 0;
    }
}