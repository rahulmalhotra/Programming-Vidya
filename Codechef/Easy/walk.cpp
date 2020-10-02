/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef WALK Problem
*   Problem Link:- https://www.codechef.com/problems/WALK
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
    int numberOfTestCases, numberOfSegments, shopAttractiveness, beginningVelocity;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of segments
        cin>>numberOfSegments;

        // * Initializing beginning velocity to 0 for the current test case
        beginningVelocity = 0;

        /*
        *   Accepting the attractiveness of shops one by one
        *   and calculating the minimum possible beginning velocity
        */
        for(int i=0; i<numberOfSegments; i++) {
            cin>>shopAttractiveness;
            beginningVelocity = max(shopAttractiveness + i, beginningVelocity);
        }

        // * Displaying the beginning velocity for the current test case
        cout<<beginningVelocity<<endl;
    }
}