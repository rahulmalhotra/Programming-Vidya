/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ATTIC Problem
*   Problem Link:- https://www.codechef.com/problems/ATTIC
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
    int numberOfTestCases, length, currentPitLength, maximumPitLength, totalDays;
    string passage;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the passage for the current test case
        cin>>passage;

        // * Calculating the length of the passage and storing it
        length = passage.length();

        /*
        *   Initializing current pit length, maximum pit length
        *   and total number of days to 0 for the current test case
        */
        currentPitLength = 0;
        maximumPitLength = 0;
        totalDays = 0;

        /*
        *   Calculating the total number of days required
        *   to cross the passage for the current test case
        */
        for(int i=0; i<length; i++) {

            // * If the floorboard is not present
            if(passage[i] == '.') {

                /*
                *   Increment the current pit length
                *   until we encounter a floorboard
                */
                while(passage[i]!='#') {
                    currentPitLength++;
                    i++;
                }

                /*
                *   If the current pit length is more than
                *   the maximum pit length encountered till now,
                *   increment the total number of days by 1
                *   and store the current pit length as the maximum pit length
                */
                if(currentPitLength > maximumPitLength) {
                    totalDays++;
                    maximumPitLength = currentPitLength;
                }

                /*
                *   Initialize the current pit length back to 0
                *   as we have encountered a floorboard now
                */
                currentPitLength = 0;
            }
        }

        /*
        *   Displaying the total number of days required to cross
        *   the passage for the current test case
        */
        cout<<totalDays<<endl;
    }
}