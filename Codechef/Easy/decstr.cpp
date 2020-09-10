/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef DECSTR Problem
*   Problem Link:- https://www.codechef.com/problems/DECSTR
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

    // * Initializing the variables
    int numberOfTestCases, k;
    string s = "zyxwvutsrqponmlkjihgfedcba";

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the length of the string
        cin>>k;

        // * Calculating the quotient and remainder using the string length
        int quotient = k/25;
        int rem = k%25;

        // * If remainder exists
        if(rem) {

            // * Displaying the extra string which is required upfront
            cout<<s.substr(25-rem, rem+1);
        }

        // * Repeating the whole string according to the value of quotient
        while(quotient--) {
            cout<<s;
        }

        // * Adding a new line at the end of the current test case
        cout<<endl;
    }
}