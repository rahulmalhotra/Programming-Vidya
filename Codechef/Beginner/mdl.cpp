/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MDL Problem
*   Problem Link:- https://www.codechef.com/problems/MDL
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing the variables
    int numberOfTestCases, numberOfIntegers, minInt, maxInt, currentInt;
    bool lastUpdatedMin = false;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the total number of integers in current test case
        cin>>numberOfIntegers;

        // * Accepting the first integer
        cin>>currentInt;

        /*
        *   Setting up the initial values for minimum and maximum Integer
        *   as the first integer for the current test case
        */
        minInt = currentInt;
        maxInt = currentInt;

        /*
        *   Calculating the overall minimum and maximum integer value
        *   by considering all the integers in the range. Also, marking
        *   wether the latest updated integer was minimum or not
        */
        for(int i=1; i<numberOfIntegers; i++) {
            cin>>currentInt;
            if(currentInt<minInt) {
                minInt = currentInt;
                lastUpdatedMin = true;
            }
            else if(currentInt>maxInt) {
                maxInt = currentInt;
                lastUpdatedMin = false;
            }
        }

        /*
        *   If minimum integer was updated most recently, it should come later
        *   otherwise, maximum integer should come after the minimum integer
        */
        if(lastUpdatedMin) {
            cout<<maxInt<<" "<<minInt<<endl;
        } else {
            cout<<minInt<<" "<<maxInt<<endl;
        }
    }
}