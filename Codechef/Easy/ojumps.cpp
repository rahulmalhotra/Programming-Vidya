/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef OJUMPS Problem
*   Problem Link:- https://www.codechef.com/problems/OJUMPS
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

    // * Initializing variable
    long long int a;

    // * Accepting the point
    cin>>a;

    /*
    *   If the point when divided by 6 gives the remainder 1 or
    *   if it's divisible by 3, print "yes". Otherwise, print "no"
    */
    if(
        a%6==1 ||
        a%3==0
    ) {
        cout<<"yes";
    } else {
        cout<<"no";
    }
}