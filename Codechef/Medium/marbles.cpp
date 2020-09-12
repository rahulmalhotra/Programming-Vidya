/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MARBLES Problem
*   Problem Link:- https://www.codechef.com/problems/MARBLES
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This function is used to return the binomial coefficient given n and r
long long int ncr(int n, int r) {

    // * Initializing result variable
    long long int result = 1;

    // * If r==0 or r==n, return 1
    if(r==0||r==n) {
        return result;
    }

    // * If r==1 or r==n-1, return n
    if(r==1||r==n-1) {
        return n;
    }

    // * If r > n-r, r = n-r because C(n, r) = C(n, n-r)
    if(r>n-r) {
        r =  n-r;
    }

    /*
    *   Calculating C(n, r):-
    *   result = (n/1) * (n-1/2) * (n-2/3) * (n-3/4).....(n-r+2)/(r-1) * (n-r+1)/r)
    */
    for(int i=0; i<r; i++) {
        result *= n-i;
        result /= i+1;
    }

    // * Returning the result
    return result;
}

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
    int n, r, numberOfTestCases;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the total number of marbles to pick and
        *   total number of colors
        */
        cin>>r>>n;

        /*
        *   As we have to pick at least one marble of each color,
        *   reduce the total number of marbles by total number of colors
        */
        r=r-n;

        // * Calculate and display the total number of possibilities
        cout<<ncr(n+r-1, r)<<endl;
    }
}