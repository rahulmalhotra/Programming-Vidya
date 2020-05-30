/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHNGIT Problem
*   Problem Link:- https://www.codechef.com/problems/CHNGIT
*/
#include <iostream>
using namespace std;
int main() {

    /*
    *   Initializing variables
    *   We've also created a frequency array and initialized it to 0
    */
    int numberOfTestCases, n, freq[101] = {0}, a, maxFreq;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the number of elements in the sequence
        *   for the current test case
        */
        cin>>n;

        // * Initializing maximum frequency variable to 0 for current test case
        maxFreq = 0;

        /*
        *   Accepting n elements, Increasing the frequency by 1 for each
        *   accepted element in the frequency array
        */
        for(int i=0; i<n; i++) {
            cin>>a;
            freq[a]++;
        }

        /*
        *   Storing the maximum frequency for the current test case
        *   and re-setting the frequency array for next test case
        */
        for(int i=1; i<=100; i++) {
            maxFreq = max(maxFreq, freq[i]);
            freq[i] = 0;
        }

        /*
        *   Minimum number of moves required =
        *   Total number of elements - Frequency of the element which occured the most
        */
        cout<<n-maxFreq<<endl;
    }
}