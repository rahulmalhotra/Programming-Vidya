/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FLOW009 Problem
*   Problem Link:- https://www.codechef.com/problems/FLOW009
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

    // * Initialzing the variables
    double numberOfTestCases, quantity, price;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

    	// * Accepting the quantity and price for the current test case
    	cin>>quantity>>price;

    	// * Displaying the total expense for the current test case
    	cout<<fixed<<setprecision(6);
    	if(quantity>1000) {
    		cout<<quantity*price*0.9<<endl;
    	} else {
    		cout<<quantity*price<<endl;
    	}
    }
}