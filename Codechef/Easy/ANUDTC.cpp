/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ANUDTC Problem
*   Problem Link:- https://www.codechef.com/problems/ANUDTC
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
    int numberOfTestCases, n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of integers
        cin>>n;

        /*
        *   Checking if it's possible to make
        *   exactly N equal pieces from the whole cake
        */
        if(360%n==0) {
            cout<<"y ";
        } else {
            cout<<"n ";
        }

        /*
        *   Checking if it's possible to make
        *   exactly N pieces from the whole cake
        */
        if(n<=360) {
            cout<<"y ";
        } else {
            cout<<"n ";
        }

        /*
        *   Checking if it's possible to make
        *   exactly N pieces from the whole cake
        *   such that no two of them are equal
        */
        if(n<=26) {
            cout<<"y";
        } else {
            cout<<"n";
        }

        // * Adding a new line before executing next test case
        cout<<endl;
    }
}