/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RRCOPY Problem
*   Problem Link:- https://www.codechef.com/problems/RRCOPY
*   Website:- www.programmingvidya.com
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
    int numberOfTestCases, n, freq[100001] = {0}, e, count;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of elements in the current test case
        cin>>n;

        // * Setting count to 0 for the current test case
        count = 0;

        // * Accepting each element one by one and calculating it's frequency
        for(int i=0; i<n; i++) {
            cin>>e;
            freq[e]++;
        }

        /*
        *   Calculating the number of unique elements in the input array
        *   and resetting the frequency array to 0 for all elements
        */
        for(int i=1; i<=100000; i++) {
            if(freq[i]) {
                count++;
            }
            freq[i] = 0;
        }

        /*
        *   Displaying the count i.e. number of unique elements
        *   for the current test case
        */
        cout<<count<<endl;
    }
}