/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FLOW010 Problem
*   Problem Link:- https://www.codechef.com/problems/FLOW010
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

	int numberOfTestCases;
	char c;

	// * Accepting the number of test cases
	cin>>numberOfTestCases;

	// * Executing each test case one by one
	while(numberOfTestCases--) {

		// * Accepting the Classs ID
		cin>>c;

		// * Displaying the Class Description according to the Class ID
		switch(c) {
			case 'b':
			case 'B':
				cout<<"BattleShip"<<endl;
				break;
			case 'c':
			case 'C':
				cout<<"Cruiser"<<endl;
				break;
			case 'd':
			case 'D':
				cout<<"Destroyer"<<endl;
				break;
			case 'f':
			case 'F':
				cout<<"Frigate"<<endl;
				break;
			default:
				break;
		}
	}
}