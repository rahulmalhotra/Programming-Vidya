/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef HORSES Problem
*   Problem Link:- https://www.codechef.com/problems/HORSES
*/
#include <iostream>
#include <algorithm>
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

    // * Initializing the variables
    int t, n, minDiff, s[5001];

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    while(t--) {

        // * Initializing minimum difference for the current test case
        minDiff = 1000000000;

        // * Accepting the number of horses
        cin>>n;

        // * Accepting the skill of each horse
        for(int i=0; i<n; i++) {
            cin>>s[i];
        }

        // * Sorting the skills
        sort(s, s+n);

        // * Finding out the minimum difference between the skills of two horses
        for(int i=1; i<n; i++) {
            minDiff = min(s[i]-s[i-1], minDiff);
        }

        // * Displaying the value of minimum difference for the current test case
        cout<<minDiff<<endl;
    }

	return 0;
}