/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef DRAGNXOR Problem
*   Problem Link:- https://www.codechef.com/problems/DRAGNXOR
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
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
    int numberOfTestCases, n, a, b, count, result, diff, mask;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the value of n, a and b
        *   count = 0
        *   result = n set bits
        */
        cin>>n>>a>>b;
        count = 0;
        result = pow(2, n) - 1;

        // * Adding the number of set bits in a to count
        while(a>0) {
            if(a&1) {
                count++;
            }
            a = a>>1;
        }

        // * Adding the number of set bits in b to count
        while(b>0) {
            if(b&1) {
                count++;
            }
            b = b>>1;
        }

        // * Finding the difference between count and n
        diff = abs(count - n);

        /*
        *   Setting up the bits that needs to be omitted from the result
        *   and preparing a mask
        */
        mask = 1;
        for(int i=0; i<diff-1; i++) {
            mask = mask<<1;
            mask++;
        }

        // * Omitting the bits from the result using mask if required
        if(diff) {
            result = result^mask;
        }

        // * Displaying the result
        cout<<result<<endl;
    }
}