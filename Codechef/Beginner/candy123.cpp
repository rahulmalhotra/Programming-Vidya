/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CANDY123 Problem
*   Problem Link:- https://www.codechef.com/problems/CANDY123
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, limakMax, bobMax, limakTotal, bobTotal;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting maximum possible candies limak and bob can eat
        cin>>limakMax>>bobMax;

        // * Initializing total candies with limak and bob to 0 for current test case
        limakTotal = 0;
        bobTotal = 0;

        // * Initializing the counter to 1
        int i = 1;

        /*
        *   Running an infinite loop, we'll break it in between
        *   when we get a solution
        */
        while(1) {

            /*
            *   If i is odd, increment total number of candies with limak  by i
            *   Otherwise, if i is even, increment total number of candies with bob by i
            */
            if(i&1) {
                limakTotal += i;
            } else {
                bobTotal += i;
            }

            /*
            *   If total number of candies with limak is more than the maximum he can eat,
            *   Bob Wins. Otherwise, if the total number of candies with bob is more than
            *   the maximum he can eat, Limak Wins.
            *   Break the loop if anyone of limak or bob wins.
            */
            if(limakTotal > limakMax) {
                cout<<"Bob"<<endl;
                break;
            }
            else if(bobTotal > bobMax) {
                cout<<"Limak"<<endl;
                break;
            }

            // * Incrementing the counter by 1
            i++;
        }
    }
}