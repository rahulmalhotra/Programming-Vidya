/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RRSUM Problem
*   Problem Link:- https://www.codechef.com/problems/RRSUM
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
    long long int n, m, q, lowerLimit, upperLimit;

    // * Accepting integer n and number of queries m
    cin>>n>>m;

    // * Calculating the lower limit and upper limit
    lowerLimit = n + 1;
    upperLimit = (3*n) + 1;

    // * Executing each query one by one
    while(m--) {

        // * Accepting the query
        cin>>q;

        // * Displaying the result for the query
        cout<<max(min(q - lowerLimit, upperLimit - q), (long long int) 0)<<endl;
    }
}