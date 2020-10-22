/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ONEKING Problem
*   Problem Link:- https://www.codechef.com/problems/ONEKING
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
    int numberOfTestCases, n, ai, bi, maxAi[2001], index, minimumNumberOfBombs;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Initializing index to -1, minimum number of bombs to 0 and
        *   all the elements of maxAi array to -1
        *   for the current test case
        */
        index = -1;
        minimumNumberOfBombs = 0;
        fill_n(maxAi, 2001, -1);

        // * Accepting the integer n for the current test case
        cin>>n;

        /*
        *   Accepting ai and bi and calculating the maximum of Ai
        *   for each range ending at index bi
        */
        for(int i=0; i<n; i++) {
            cin>>ai>>bi;
            maxAi[bi] = max(ai, maxAi[bi]);
        }

        // * Checking each range to find the minimum number of bombs required
        for(int i=0; i<=2000; i++) {

            /*
            *   If the current index is less than the maximum Ai
            *   encountered relative to i, increment the minimum number of bombs by 1.
            *   Also set the index to i
            */
            if(index < maxAi[i]) {
                minimumNumberOfBombs++;
                index = i;
            }

            // * Reset maxAi array for the next test case
            maxAi[i] = -1;
        }

        // * Display the minimum number of bombs required for the current test case
        cout<<minimumNumberOfBombs<<endl;
    }

	return 0;
}