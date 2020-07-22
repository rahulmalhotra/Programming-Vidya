/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef DECINC Problem
*   Problem Link:- https://www.codechef.com/problems/DECINC
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
    int n;

    // * Accepting the number 'n'
    cin>>n;

    /*
    *   If number 'n' is divisible by 4,
    *   increment the value of n by 1.
    *   Otherwise, decrement it's value by 1
    */
    if(n%4 == 0) {
        n++;
    } else {
        n--;
    }

    // * Displaying the number n
    cout<<n;
}