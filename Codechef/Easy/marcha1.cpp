/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MARCHA1 Problem
*   Problem Link:- https://www.codechef.com/problems/MARCHA1
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
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
	int numberOfTestCases, n, m, arr[20], sum;
    bool sumFound;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing sum found to false for the current test case
        sumFound = false;

        // * Accepting the number of bank notes and the amount asked
        cin>>n>>m;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        for(int j=1; j<=pow(2,n); j++) {
            sum=0;
            for(int k=0;k<n;k++) {
                if((j>>(k)) & 1) {
                    sum+=arr[k];
                }
            }
            if(sum==m) {
                sumFound = true;
            }
        }
        if(sumFound) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

	return 0;
}