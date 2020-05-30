/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHOPRT Problem
*   Problem Link:- https://www.codechef.com/problems/CHOPRT
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, a, b;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting integers a and b for each test case
        cin>>a>>b;

        /*
        *   If a is less than b, displaying "<"
        *   If a is greater than b, displaying ">"
        *   Otherwise (If a is equal to b), displaying "="
        */
        if(a<b) {
            cout<<"<"<<endl;
        } else if(a>b) {
            cout<<">"<<endl;
        } else {
            cout<<"="<<endl;
        }
    }
}