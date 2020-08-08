/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MAXDIFF Problem
*   Problem Link:- https://www.codechef.com/problems/MAXDIFF
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
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
    int numberOfTestCases, n, k, w[100], s1, s2, s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the values for n and k
        cin>>n>>k;

        /*
        *   Initializing the total sum and
        *   the sum of k items from start and end to 0
        *   for the current test case
        */
        s=0;
        s1=0;
        s2=0;

        // * Accepting the weight of i items and calculating the total sum
        for(int i=0; i<n; i++) {
            cin>>w[i];
            s+=w[i];
        }

        // * Sorting the weight for n items
        sort(w, w+n);

        /*
        *   Calculating the sum of weight of k items in the
        *   sorted list from start & end
        */
        for(int i=0; i<k; i++) {
            s1+=w[i];
            s2+=w[n-i-1];
        }

        /*
        *   Calculating the maximum value of the difference between
        *   two groups with k and n-k items from start & end
        */
        cout<<max(abs(s-2*s1), abs(s-2*s2))<<endl;
    }

	return 0;
}