/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ALEXNUMB Problem
*   Problem Link:- https://www.codechef.com/problems/ALEXNUMB
*   Website:- www.programmingvidya.com
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
    long long int numberOfTestCases, n, a;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of integers
        cin>>n;

        // * Accepting each integer one by one
        for(int i=0; i<n; i++) {
            cin>>a;
        }

        // * Displaying the result for the current test case
        cout<<n*(n-1)/2<<endl;
    }
}