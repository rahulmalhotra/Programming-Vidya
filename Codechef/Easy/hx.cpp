/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef HX Problem
*   Problem Link:- https://www.codechef.com/problems/HX
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
    int n, charge;

    // * Accepting the size of input
    cin>>n;

    // * Accepting the input
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>charge;
        }
    }

    // * Displaying the output i.e. polarization of charges
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i&1 && j&1) {
                cout<<"1 ";
            } else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}