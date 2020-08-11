/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ERROR Problem
*   Problem Link:- https://www.codechef.com/problems/ERROR
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

    // * Setting up the variables with initial values
    int numberOfTestCases, feedbackLength;
    bool good;
    string feedback;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the feedback for the current test case
        cin>>feedback;

        // * Calculating the length of feedback and setting variable good to false
        feedbackLength = feedback.size();
        good = false;

        /*
        *   Checking if the feedback consist of the substring
        *   "010" or the substring "101", if that's true,
        *   set the variable good to true as the feedback is good
        */
        for(int i=0; i<feedbackLength-2; i++) {
            if(
                (feedback[i]=='0' && feedback[i+1]=='1' && feedback[i+2]=='0') ||
                (feedback[i]=='1' && feedback[i+1]=='0' && feedback[i+2]=='1')
            ) {
                good = true;
            }
        }

        /*
        *   If the feedback is good, display "Good"
        *   otherwise, display "Bad"
        */
        if(good) {
            cout<<"Good"<<endl;
        } else {
            cout<<"Bad"<<endl;
        }
    }
}