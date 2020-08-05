/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef STONES Problem
*   Problem Link:- https://www.codechef.com/problems/STONES
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
    int numberOfTestCases, count, jewelSize, stoneSize;
    string jewels, stones;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing count and jewelFound array values with 0
        count = 0;
        int jewelFound[125] = {0};

        // * Accepting the value of jewels and stones
        cin>>jewels>>stones;

        // * Calculating the size of jewels and stones
        jewelSize = jewels.size();
        stoneSize = stones.size();

        /*
        *   Iterating the jewels string and
        *   marking jewelFound array items with value 1,
        *   for each jewel in the jewels string
        */
        for(int i=0; i<jewelSize; i++) {
            jewelFound[jewels[i]] = 1;
        }

        /*
        *   Iterating the stones string and checking if
        *   the current character has occured in jewels string,
        *   if that's the case, increment the count by 1
        */
        for(int i=0; i<stoneSize; i++) {
            if(jewelFound[stones[i]]==1) {
                count++;
            }
        }

        // * Display the value of count for the current test case
        cout<<count<<endl;
    }

	return 0;
}