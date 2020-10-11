/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RRSTONE Problem
*   Problem Link:- https://www.codechef.com/problems/RRSTONE
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <climits>
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
    long long int a[100000], maxA = 0, minA = INT_MAX;
    int numberOfIntegers, numberOfTurns;

    // * Accepting the number of integers and number of turns
    cin>>numberOfIntegers>>numberOfTurns;

    /*
    *   Accepting the number of integers one by one
    *   and calculating the maximum integer and minimum integer
    *   out of all the integers in the array
    */
    for(int i=0; i<numberOfIntegers; i++) {
        cin>>a[i];
        maxA = max(maxA, a[i]);
        minA = min(minA, a[i]);
    }

    // * If the number of turns are 0, display the array as it is
    if(numberOfTurns==0) {
        for(int i=0; i<numberOfIntegers; i++) {
            cout<<a[i]<<" ";
        }
    }

    /*
    *   If the number of turns are odd,
    *   display the final array of integers
    *   in which each integer a[i] = maxA - a[i]
    *   where maxA = maximum integer in initial array
    */
    else if(numberOfTurns&1) {
        for(int i=0; i<numberOfIntegers; i++) {
            a[i] = maxA - a[i];
            cout<<a[i]<<" ";
        }
    }

    /*
    *   If the number of turns are even,
    *   display the final array of integers
    *   in which each integer a[i] = a[i] - minA
    *   where minA = minimum integer in initial array
    */
    else {
        for(int i=0; i<numberOfIntegers; i++) {
            a[i] = a[i] - minA;
            cout<<a[i]<<" ";
        }
    }
}