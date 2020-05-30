/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ADASCOOL Problem
*   Problem Link:- https://www.codechef.com/problems/ADASCOOL
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, n, m;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the values of number of rows and columns
        *   for current test case
        */
        cin>>n>>m;

        /*
        *   Calculating the total number of tables in classroom = n*m
        *   If the total number of tables are odd, the answer is NO
        *   Otherwise, if the total number of tables are even, the answer is YES
        *   Calculating and displaying answer for current test case
        */
        if((n*m) & 1) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
}