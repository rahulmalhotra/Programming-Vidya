/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHEFSTLT Problem
*   Problem Link:- https://www.codechef.com/problems/CHEFSTLT
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, minDiff, maxDiff, i;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing minDiff, maxDiff and i to 0 for current test case
        minDiff = 0;
        maxDiff = 0;
        i = 0;

        // * Initializing the strings s1 and s2
        char s1[100], s2[100];

        // * Accepting s1 and s2
        cin>>s1>>s2;

        /*
        *   Looping while we don't encounter null character '\0'
        *   in string 1, as both the strings have equal length
        */
        while(s1[i]!='\0') {

            /*
            *   If the characters at index i in both strings are not equal
            *   and also, none of the character is a question mark,
            *   We need to increment both min and max differences
            */
            if(
                s1[i]!=s2[i] &&
                s1[i]!='?' &&
                s2[i]!='?'
            ) {
                minDiff++;
                maxDiff++;
            }

            /*
            *   If any of the character is a question mark while comparing
            *   same indexes in two strings, increment only the max difference
            */
            else if(
                s1[i] == '?' ||
                s2[i] == '?'
            ) {
                maxDiff++;
            }

            // * Increment the index counter i
            i++;
        }

        /*
        *   Displaying minimum difference and maximum difference
        *   between strings s1 and s2 for the current test case
        */
        cout<<minDiff<<" "<<maxDiff<<endl;
    }
}