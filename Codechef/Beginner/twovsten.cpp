/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TWOVSTEN Problem
*   Problem Link:- https://www.codechef.com/problems/TWOVSTEN
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, number;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting number for the current test case
        cin>>number;

        /*
        *   To make a number divisible by 10, we should have
        *   0 at it's unit place. As we can multiply by 2 only,
        *   this means that either the number should have 0 at it's
        *   unit place initially or it should have 5, so that we can multiply
        *   it by 2 in order to have a 0 at the unit place.
        *   If these two are not the cases, number cannot be made
        *   divisible by 10 by multiplying it by 2 any number of times
        */
        if(number%10==0) {
            cout<<"0"<<endl;
        } else if(number*2%10==0) {
            cout<<"1"<<endl;
        } else {
            cout<<"-1"<<endl;
        }
    }
}