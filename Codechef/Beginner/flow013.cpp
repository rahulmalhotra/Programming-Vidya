/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FLOW013 Problem
*   Problem Link:- https://www.codechef.com/problems/FLOW013
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
	int numberOfTestCases, a, b, c;

	// * Accepting the number of test cases
	cin>>numberOfTestCases;

	// * Executing each test case one by one
	while(numberOfTestCases--) {

		// * Accepting the value for angle a, b and c
		cin>>a>>b>>c;

		/*
		*	If the sum of all 3 angles of the triangle
		*	is equal to 180 degree, print "YES" otherwise,
		*	print "NO"
		*/
		if((a+b+c)==180) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}