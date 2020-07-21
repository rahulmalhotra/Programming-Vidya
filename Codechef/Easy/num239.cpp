/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef NUM239 Problem
*   Problem Link:- https://www.codechef.com/problems/NUM239
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

    // * Initializing the variables
    int t, l, r, lastDigit, totalPrettyNumbers;

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    for(int i=0; i<t; i++) {

        // * Initializing total pretty numbers for the current test case to 0
        totalPrettyNumbers = 0;

        // * Accepting the numbers L and R for the current test case
        cin>>l>>r;

        // * Considering all numbers between L and R one by one for the current test case
        for(int i=l; i<=r; i++) {

            // * Getting the last digit of the current number
            lastDigit = i%10;

            // * If the current number is a pretty number, increment the total number of pretty numbers by 1
            if(
                lastDigit==2 ||
                lastDigit==3 ||
                lastDigit==9
            ) {
                totalPrettyNumbers++;
            }
        }

        // * Displaying the total number of pretty numbers for the current test case
        cout<<totalPrettyNumbers<<endl;
    }
}