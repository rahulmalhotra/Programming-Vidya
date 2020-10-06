/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef SUBGCD Problem
*   Problem Link:- https://www.codechef.com/problems/SUBGCD
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This method is used to return gcd of two numbers
int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
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
    int numberOfTestCases, n, a, result, i;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the number of integers
        *   for the current test case
        */
        cin>>n;

        // * Initializing result to 0 for the current test case
        result = 0;

        /*
        *   Calculating the gcd of all integers and
        *   storing it in the result
        */
        for(i=0; i<n; i++) {
            cin>>a;
            result = gcd(result, a);
        }

        /*
        *   If the result is 1, display n. As the size of
        *   largest contiguous subarray is the size of array itself
        */
        if(result==1) {
            cout<<n<<endl;
        }

        // * Otherwise, display -1
        else {
            cout<<"-1"<<endl;
        }
    }
}