/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHEFSTR1 Problem (July Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JULY20B/problems/CHEFSTR1
*/
#include <iostream>
#include <stdio.h>
#include <cmath>
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
    long long totalNumberOfStringToSkip;
    int t, n, currentIndex = 1, stringToPluck, currentSkips;

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    while(t--) {

        /*
        *   Initializing total number of strings to skip for the current
        *   test case to 0
        */
        totalNumberOfStringToSkip = 0;

        // * Accepting the number of times, chef has to pluck a string
        cin>>n;

        /*
        *   Accepting the first string to pluck and setting the current index
        *   to the index of the first string, decrementing the number of times,
        *   chef has to pluck a string by one
        */
        cin>>stringToPluck;
        currentIndex = stringToPluck;
        n--;

        // * Chef is plucking the strings of the string one by one
        while(n--) {
            cin>>stringToPluck;

            // * Calculating the number of strings to skip to pluck the current string
            currentSkips = abs(stringToPluck - currentIndex);
            currentSkips = currentSkips == 0 ? 0 : currentSkips - 1;

            // * Adding the number of strings skipped to the total number
            totalNumberOfStringToSkip += currentSkips;

            // * Updating the current index to the value of current string plucked
            currentIndex = stringToPluck;
        }

        // * Displaying the total number of strings chef has to skip
        cout<<totalNumberOfStringToSkip<<endl;
    }
}