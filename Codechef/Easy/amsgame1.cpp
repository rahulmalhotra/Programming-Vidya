/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef AMSGAME1 Problem
*   Problem Link:- https://www.codechef.com/problems/AMSGAME1
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This function will return the gcd of two integers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

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
    int numberOfTestCases, n, result, i;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of integers for the current test case
        cin>>n;

        // * Accepting the first integer and storing it as the result
        cin>>result;

        /*
        *   Accepting the remaining n-1 integers, calculating the gcd
        *   and updating the result
        */
        while(--n) {
            cin>>i;
            result = gcd(result, i);
        }

        // * Displaying the result for the current test case
        cout<<result<<endl;
    }
}