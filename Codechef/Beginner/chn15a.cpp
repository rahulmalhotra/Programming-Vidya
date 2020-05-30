/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHN15A Problem
*   Problem Link:- https://www.codechef.com/problems/CHN15A
*/
#include <iostream>
using namespace std;

int main() {

    // * Initializing variables
    int numberOfTestCases, n, k, e, count;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the elements n and k for the current test case
        cin>>n>>k;

        // * Initializing the count to 0 for the current test case
        count = 0;

        // * Accepting n elements
        for(int i=0; i<n; i++) {

            cin>>e;

            /*
            *   If the sum of current element e and k,
            *   becomes divisible by 7, increment the count by 1
            */
            if((e+k)%7==0) {
                count++;
            }
        }

        // * Displaying the count for current test case
        cout<<count<<endl;
    }
}