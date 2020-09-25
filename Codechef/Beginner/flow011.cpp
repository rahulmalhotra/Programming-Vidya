/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FLOW011 Problem
*   Problem Link:- https://www.codechef.com/problems/FLOW011
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <iomanip>
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
    int numberOfTestCases, basicSalary;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

    	// * Accepting the basic salary for the current test case
    	cin>>basicSalary;

    	// * Displaying the gross salary for the current test case
    	cout<<fixed<<setprecision(2);
    	if(basicSalary<1500) {
    		cout<<basicSalary*2<<endl;
    	} else {
    		cout<<basicSalary+basicSalary*0.98+500<<endl;
    	}
    }
}