/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHEFSTON Problem
*   Problem Link:- https://www.codechef.com/problems/CHEFSTON
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

    // * Initializing variables
    int numberOfTestCases, kindsOfStones, minutesOfFreeTime;
    int minutes[100000], profit[100000];
    long long int maximumProfit;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the kinds of stones and
        *   the minutes of free time for the current test case
        */
        cin>>kindsOfStones>>minutesOfFreeTime;

        // * Initializing maximum profit to 0 for the current test case
        maximumProfit = 0;

        // * Accepting the minutes to pick each kind of stone
        for(int i=0; i<kindsOfStones; i++) {
            cin>>minutes[i];
        }

        // * Acceptng the profit by each kind of stone
        for(int i=0; i<kindsOfStones; i++) {
            cin>>profit[i];
        }

        /*
        *   Calculating the maximum profit according to the
        *   minutes of free time we have for the current test case
        */
        for(int i=0; i<kindsOfStones; i++) {
            maximumProfit = max(maximumProfit, (long long int) profit[i] * (minutesOfFreeTime / minutes[i]));
        }

        // * Displaying the maximum profit for the current test case
        cout<<maximumProfit<<endl;
    }
}