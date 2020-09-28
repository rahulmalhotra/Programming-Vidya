/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ANUWTA Problem
*   Problem Link:- https://www.codechef.com/problems/ANUWTA
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

    // * Declaring the variables
    int numberOfTestCases;
    long long int n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number 'n' for the current test case
        cin>>n;

        // * Displaying the result for the current test case
        cout<<(n*(n+1))/2 + n;

        // * Adding a new line before executing the next test case
        cout<<endl;
    }
}