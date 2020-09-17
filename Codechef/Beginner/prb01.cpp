/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PRB01 Problem
*   Problem Link:- https://www.codechef.com/problems/PRB01
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
    int numberOfTestCases, n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number n for the current test case
        cin>>n;

        // * Checking if n is prime or not
        if(checkPrime(n)) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }

    }
}