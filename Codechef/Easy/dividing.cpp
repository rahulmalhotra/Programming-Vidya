/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef DIVIDING Problem
*   Problem Link:- https://www.codechef.com/problems/DIVIDING
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
typedef long long ll;
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

    // * Declaring the variables
    int n, c;
    ll actualStamps = 0, expectedStamps;

    // * Accepting number of members in the community
    cin>>n;

    /*
    *   Calculating the expected number of stamps that community
    *   must have so that it can be distributed according to Mike
    */
    expectedStamps = (ll) n*(n+1)/2;

    /*
    *   Calculating the total number of stamps
    *   that community has in actual
    */
    for(int i=0; i<n; i++) {
        cin>>c;
        actualStamps += c;
    }

    /*
    *   If total number of expected stamps is
    *   equal to the actual number of stamps, print "YES".
    *   Otherwise, print "NO"
    */
    if(expectedStamps == actualStamps) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}