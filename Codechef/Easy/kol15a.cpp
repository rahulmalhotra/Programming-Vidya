/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef KOL15A Problem
*   Problem Link:- https://www.codechef.com/problems/KOL15A
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

    // * Initializing the variables
    int numberOfTestCases, sum, length, number;
    string s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the string
        cin>>s;

        // * Initializing sum to 0 for current test case
        sum = 0;
        length = s.size();

        // * Checking each character of the string one by one
        for(int i=0; i<length; i++) {

            /*
            *   Checking the ascii value to confirm if
            *   the character lies between 0 to 9
            */
            if(s[i]>=48 && s[i]<=57) {

                // * Converting the character into integer
                number = s[i] - '0';

                // * Adding the number to the sum
                sum += number;
            }
        }

        // * Displaying the sum for the current test case
        cout<<sum<<endl;
    }
}