/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TAVISUAL Problem
*   Problem Link:- https://www.codechef.com/problems/TAVISUAL
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Initializing variables
    int numberOfTestCases, numberOfCups, positionOfBall, numberOfFlips, start, end;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the number of cups,
        *   initial position of ball and the number of flips
        *   for the current test case
        */
        cin>>numberOfCups>>positionOfBall>>numberOfFlips;

        /*
        *   Executing each flip one by one and
        *   calculating the position of ball after each flip
        */
        while(numberOfFlips--) {

            /*
            *   Accepting the beginning and end position
            *   of the segment for the current flips
            */
            cin>>start>>end;

            /*
            *   If the position of ball >= start position and
            *   the position of ball <= end position. Position of ball after flips
            *   can be given as:- end position - (position of ball - start position)
            */
            if(positionOfBall>=start && positionOfBall<=end) {
                positionOfBall = end - (positionOfBall - start);
            }
        }

        /*
        *   Displaying the position of ball after all the flips
        *   occured for the current test case
        */
        cout<<positionOfBall<<endl;
    }
}