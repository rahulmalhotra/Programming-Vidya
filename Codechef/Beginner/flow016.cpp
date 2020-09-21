/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FLOW016 Problem
*   Problem Link:- https://www.codechef.com/problems/FLOW016
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This function is used to return the GCD of two numbers
long long int gcd(long long int a, long long int b) {

	if(b==0) {
		return a;
	}

	return gcd(b, a%b);
}

// * This function is used to return the LCM of two numbers
long long int lcm(long long int a, long long int b) {

	return (a*b) / gcd(a,b);
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
    int numberOfTestCases, a, b;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

    	// * Accepting two numbers for the current test case
    	cin>>a>>b;

    	// * Calculating and displaying the GCD and LCM of two numbers
    	cout<<gcd(a, b)<<" "<<lcm(a,b);

    	// * Adding a new line before executing the next test case
    	cout<<endl;
    }
}