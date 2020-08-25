/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef NUMGAME2 Problem
*   Problem Link:- https://www.codechef.com/problems/NUMGAME2
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
    while (numberOfTestCases--)
    {
        // * Accepting the number 'n'
        cin>>n;

        // * If n, when divided by 4, gives the remainder 1, ALICE wins
        if(n%4 == 1) {
            cout<<"ALICE";
        }

        // * Otherwise, BOB wins
        else {
            cout<<"BOB";
        }

        // * Adding a new line before executing the next test case
        cout<<endl;
    }
}