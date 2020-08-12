/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PRIME1 Problem
*   Problem Link:- https://www.codechef.com/problems/PRIME1
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This function is used to check if a number is prime or not
bool checkPrime(int num) {

    // * If number is 1, return false
    if(num==1) {
        return false;
    }

    /*
    *   Initialize counter with 2, loop till
    *   square root of input number and check,
    *   if the current number is divisible by counter at any instant,
    *   return false as the current number is not prime.
    *   Otherwise, return true
    */
    for(int i=2; i*i<=num;  i++) {
        if(num%i==0) {
            return false;
        }
    }
    return true;
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

    // * Declaring the variables
    int numberOfTestCases, m, n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the values of m and n for the current test case
        cin>>m>>n;

        /*
        *   Looping counter from m to n,
        *   if the current value of counter is prime,
        *   display it.
        */
        for(int i=m; i<=n; i++) {
            if(checkPrime(i)) {
                cout<<i<<endl;
            }
        }

        // * Adding a new line before executing next test case
        cout<<endl;
    }
}