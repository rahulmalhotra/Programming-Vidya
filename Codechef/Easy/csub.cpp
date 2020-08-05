/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CSUB Problem
*   Problem Link:- https://www.codechef.com/problems/CSUB
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
    int numberOfTestCases, lengthOfString, numberOfOnes;
    string s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing number of 1s to 0 for the current test case
        numberOfOnes = 0;

        // * Accepting the length of the string and string s
        cin>>lengthOfString>>s;

        // * Iterating over the string and calculating the number of 1's in the string
        for(int i=0; i<lengthOfString; i++) {
            if(s[i]=='1') {
                numberOfOnes++;
            }
        }

        // * Displaying the result
        cout<<(long long)(numberOfOnes+1)*numberOfOnes/2<<endl;
    }

	return 0;
}