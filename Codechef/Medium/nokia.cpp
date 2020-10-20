/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef NOKIA Problem
*   Problem Link:- https://www.codechef.com/problems/NOKIA
*	Website:- www.programmingvidya.com
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

    /*
    *   Initializing variables
    *   min and max arrays are used to store the minimum possible length
    *   and maximum possible length of wire required to place soldiers
    *   among i number of spots in all possible permutations, where i is
    *   ranging from 1 to 30
    */
	int min[31], max[31], numberOfTestCases, numberOfSpots, lengthOfWire, quotient, remainder;

    /*
    *   Calculating the minimum possible length array
    *   for each number of spots from 1 to 30
    */
	min[1] = 2;
	min[2] = 5;
	for(int i=3; i<=30; i++) {
	    quotient = (i+1)/2;
	    remainder = (i+1)%2;
	    min[i] = (i+1) + min[quotient-1] + min[quotient+remainder-1];
    }

    /*
    *   Calculating the maximum possible length array
    *   for each number of spots from 1 to 30
    */
    max[1] = 2;
    for(int i=2; i<=30; i++) {
        max[i] = (i+1) + max[i-1];
    }

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the number of spots and the length of wire
        *   for the current test case
        */
        cin>>numberOfSpots>>lengthOfWire;

        /*
        *   If the length of wire is less than the
        *   minimum length required to place the soldiers
        *   among the current number of spots, display -1
        */
        if(lengthOfWire < min[numberOfSpots]) {
            cout<<"-1"<<endl;
        }

        /*
        *   If the length of wire is more than the
        *   maximum length required to place the soldiers
        *   among current number of spots, display the
        *   extra length of wire that we have
        */
        else if(lengthOfWire > max[numberOfSpots]) {
            cout<<lengthOfWire-max[numberOfSpots]<<endl;
        }

        /*
        *   Otherwise it means that the length of wire
        *   is in between the minimum and maximum length required
        *   to place the soldiers among current number of spots,
        *   display "0"
        */
        else {
            cout<<"0"<<endl;
        }
    }

	return 0;
}