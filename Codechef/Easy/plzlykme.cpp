/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PLZLYKME Problem
*   Problem Link:- https://www.codechef.com/problems/PLZLYKME
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
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
    int numberOfTestCases;
    double l, d, s, c, totalLikes;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the integers for the current test case
	    cin>>l>>d>>s>>c;

        // * Calculating the total number of likes after d days
	    totalLikes = s*pow(1+c, d-1);

        /*
        *   If the total number of likes is greater than or equal to l,
        *   print "ALIVE AND KICKING" otherwise, print "DEAD AND ROTTING"
        */
	    if(totalLikes>=l) {
	        cout<<"ALIVE AND KICKING"<<endl;
	    } else {
	        cout<<"DEAD AND ROTTING"<<endl;
	    }
    }
}