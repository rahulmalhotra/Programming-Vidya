/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef BUYING2 Problem
*   Problem Link:- https://www.codechef.com/problems/BUYING2
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

    // * Declaring the variables
    int numberOfTestCases, numberOfBankNotes, priceOfSweet, bankNotes[100], totalAmount, minAmount;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the values of number of bank notes
        *   and price of sweet for the current test case
        */
        cin>>numberOfBankNotes>>priceOfSweet;

        // * Initializing the total amount and minimum amount variables
        totalAmount = 0;
        minAmount = 101;

        /*
        *   Accepting each bank note,
        *   calculating the total amount
        *   and minimum amount (minimum value bank note)
        */
        for(int i=0; i<numberOfBankNotes; i++) {
            cin>>bankNotes[i];
            totalAmount += bankNotes[i];
            minAmount = min(minAmount, bankNotes[i]);
        }

        /*
        *   If the amount left after purchasing sweets is greater than
        *   or equal to the amount on the minimum value bank note,
        *   this means that the customer is inadequate as he has given
        *   extra banknotes, display "-1". Otherwise,
        *   display the number of sweets purchased using the total amount
        */
        if(
            totalAmount%priceOfSweet >= minAmount
        ) {
            cout<<"-1"<<endl;
        } else {
            cout<<totalAmount/priceOfSweet<<endl;
        }
    }
}