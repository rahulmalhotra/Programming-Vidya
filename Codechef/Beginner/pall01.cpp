/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PALLO1 Problem
*   Problem Link:- https://www.codechef.com/problems/PALLO1
*   Website:- www.programmingvidya.com
*/
#include<iostream>
#include<stdio.h>
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
    int numberOfTestCases, n, n1, n2;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the integer n
        cin>>n;

        // * Initializing n1 and n2 for comparison in the current test case
        n1 = n;
        n2 = 0;

        // * Calculating the reverse of n and storing it in n2
        while(n!=0) {
            n2 = n2*10 + n%10;
            n = n/10;
        }

        // * If both the integers n1 and n2 are equal, display "wins"
        if(n1==n2) {
            cout<<"wins"<<endl;
        }

        // * Otherwise, display "loses"
        else {
            cout<<"loses"<<endl;
        }
    }
}