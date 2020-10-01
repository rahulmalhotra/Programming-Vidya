/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef LUCKY5 Problem
*   Problem Link:- https://www.codechef.com/problems/LUCKY5
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
    int numberOfTestCases, length, count;
    string n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number n
        cin>>n;

        /*
        *   Calculating the length of number n and
        *   initializing count to 0 for the current test case
        */
        length = n.length();
        count = 0;

        /*
        *   Checking each digit of n one by one.
        *   If the current digit is not a lucky digit,
        *   increment count by 1
        */
        for(int i=0; i<length; i++) {
            if(n[i]!='4' && n[i]!='7') {
                count++;
            }
        }

        // * Display the value of count for the current test case
        cout<<count<<endl;
    }
}