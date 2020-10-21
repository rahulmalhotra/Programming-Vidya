/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ARRAYTRM Problem
*   Problem Link:- https://www.codechef.com/problems/ARRAYTRM
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
    int numberOfTestCases, n, k, a, mod[12] = {0}, i;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the integers n and k for the current test case
        cin>>n>>k;

        /*
        *   Accepting n integers.
        *   Calculating the modulus of each integer by dividing it with (k+1)
        *   and incrementing it's frequency by 1
        */
        for(i=0; i<n; i++) {
            cin>>a;
            mod[a%(k+1)]++;
        }

        /*
        *   If any modulus value is having a frequency
        *   greater than or equal to n-1, display "YES"
        *   and break the loop
        */
        for(i=0; i<12; i++) {
            if(mod[i]>=n-1) {
                cout<<"YES"<<endl;
                break;
            }
        }

        /*
        *   If the counter reached the end of modulus array,
        *   display "NO"
        */
        if(i==12) {
            cout<<"NO"<<endl;
        }

        /*
        *   Resetting the modulus frequency array with 0
        *   for the next test case
        */
        for(i=0; i<12; i++) {
            mod[i] = 0;
        }
    }

	return 0;
}