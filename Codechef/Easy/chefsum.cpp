/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHEFSUM Problem
*   Problem Link:- https://www.codechef.com/problems/CHEFSUM
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <climits>
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
    int numberOfTestCases, numberOfIntegers, minSumIndex, a[100000];
    long long int totalSum, minSum, currentSum;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of integers for the current test case
        cin>>numberOfIntegers;

        /*
        *   Initializing total sum to 0 and
        *   minimum sum to maximum possible value
        *   for the current test case
        */
        totalSum = 0;
        minSum = LLONG_MAX;

        /*
        *   Accepting the integers one by one
        *   and calculating the total sum
        */
        for(int i=0; i<numberOfIntegers; i++) {
            cin>>a[i];
            totalSum += a[i];
        }

        /*
        *   Calculating the value of prefixSum(i) + suffixSum(i)
        *   for the element at index i and storing that in
        *   the current sum. If the current sum is less than
        *   the minimum sum, store the current sum as the minimum sum
        *   and also update the minimum sum index as the
        *   index of current element + 1
        */
        for(int i=0; i<numberOfIntegers; i++) {
            currentSum = totalSum + a[i];
            if(currentSum < minSum) {
                minSum = currentSum;
                minSumIndex = i + 1;
            }
        }

        // * Displaying the minimum sum index for the current test case
        cout<<minSumIndex<<endl;
    }
}