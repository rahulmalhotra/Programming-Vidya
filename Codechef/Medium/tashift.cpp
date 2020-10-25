/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TASHIFT Problem
*   Problem Link:- https://www.codechef.com/problems/TASHIFT
*	Website:- www.programmingvidya.com
*/

#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

/*
*   This function is used to calculate the minimum required shift
*   operations to maximize the length of longest common prefix
*   of string a and b
*/
int calculateMinimumShifts(int n, string a, string b) {

    // * Initializing variables
    int count = 0, maxCount = 0, currentShifts, minimumShifts = INT_MAX;

    // * Iterating all the characters of string b one by one
    for(int i=0, j=0; i<n; i++) {

        /*
        *   If the character of string b at index  i
        *   is equal to the character of string a at index j
        */
        if(b[i]==a[j]) {

            /*
            *   If count is 0, initialize current shifts to i
            *   as we have the first character in the current substring of b
            *   matching with the first character of a
            */
            if(count==0) {
                currentShifts = i;
            }

            // * Increment the count and j by 1
            count++;
            j++;
        }

        // * Otherwise
        else {

            /*
            *   If the current substring characters count is
            *   more than the maximum count, assign current count
            *   to the maximum count and assign current shifts
            *   to the minimum shifts
            */
            if(count>maxCount) {
                maxCount = count;
                minimumShifts = currentShifts;
            }

            /*
            *   If count is more than 0, we need to consider the
            *   current character of string b again in the next substring.
            *   Therefore, decrement i by 1
            */
            if(count>0) {
                i--;
            }

            // * Resetting count and j to 0 for the next substring
            count = 0;
            j=0;
        }
    }

    /*
    *   If the whole string b is scanned and
    *   the last substring's count is more than maximum count,
    *   assign current count to the maximum count and
    *   assign current shifts to the minimum shifts
    */
    if(count>maxCount) {
        maxCount = count;
        minimumShifts = currentShifts;
    }

    // * Return the minimum shifts
    return minimumShifts;
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

    // * Initializing variables
    int n;
    string a, b;

    // * Accepting the length of strings and the strings a and b
    cin>>n>>a>>b;

    /*
    *   Calculating and displaying the minimum required shifts
    *   to maximize the length of longest common prefix
    *   of string a and b
    */
    cout<<calculateMinimumShifts(n, a, b);

	return 0;
}