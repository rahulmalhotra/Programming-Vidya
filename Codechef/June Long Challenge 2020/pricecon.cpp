/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PRICECON Problem (June Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JUNE20B/problems/PRICECON
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, numberOfItems, ceilingPrice, price, lostRevenue;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing lost revenue to 0 for the current test case
        lostRevenue = 0;

        // * Getting number of items and ceiling price for the current test case
        cin>>numberOfItems>>ceilingPrice;

        /*
        *   Accepting price of all items one by one. If price of current item
        *   is greater than price ceiling, update lost revenue for current
        *   test case by adding the revenue loss for current item
        *   Revenue loss for current item = Price of Current Item - Ceiling Price
        */
        for(int i=0; i<numberOfItems; i++) {
            cin>>price;
            if(price>ceilingPrice) {
                lostRevenue += price - ceilingPrice;
            }
        }

        // * Displaying revenue loss for current test case
        cout<<lostRevenue<<endl;
    }
}