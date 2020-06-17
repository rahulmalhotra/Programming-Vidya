/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHFICRM Problem (June Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JUNE20B/problems/CHFICRM
*/
#include <iostream>
#include <limits>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, numberOfPersons, numberOfFiveRupeeCoins = 0, numberOfTenRupeeCoins = 0, coin, i;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Clearing the buffer memory before taking input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        /*
        *   Accepting the total number of persons
        *   for the current test case
        */
        cin>>numberOfPersons;

        // * Considering each person one by one
        for(i=0; i<numberOfPersons; i++) {

            // * Accepting the value of coin with the current person
            cin>>coin;

            /*
            *   If coin's value is equal to 5,
            *   increment the number of 5 rupee coins by 1
            */
            if(coin==5) {
                numberOfFiveRupeeCoins++;
            }
            /*
            *   If coin's value is equal to 10,
            *   and we have a 5 rupee coin present to return,
            *   increment the number of 10 rupee coins by 1
            *   and decrement the number of 5 rupee coins by 1
            */
            else if(
                coin==10 &&
                (numberOfFiveRupeeCoins > 0)
            ) {
                numberOfTenRupeeCoins++;
                numberOfFiveRupeeCoins--;
            }
            /*
            *   If coin's value is equal to 15,
            *   and we have a 10 rupee coin present to return,
            *   decrement the number of 10 rupee coins by 1,
            *   otherwise if we don't have a 10 rupee coin present to return,
            *   but we have at least 2 - 5 rupee coins present to return,
            *   decrement the number of 5 rupee coins by 2
            */
            else if(
                coin==15
            ) {
                if(numberOfTenRupeeCoins>0) {
                    numberOfTenRupeeCoins--;
                } else if(numberOfFiveRupeeCoins>1) {
                    numberOfFiveRupeeCoins-=2;
                }
                /*
                *   If we don't have any coins present to return,
                *   break the loop
                */
                else {
                    break;
                }
            }
            // * Otherwise, break the loop
            else {
                break;
            }
        }

        /*
        *   Re-initializing number of 5 rupee coins and
        *   number of 10 rupee coins to 0
        *   for next test case
        */
        numberOfFiveRupeeCoins = 0;
        numberOfTenRupeeCoins = 0;

        /*
        *   If all persons are served, display YES,
        *   otherwise, display NO
        */
        if(i==numberOfPersons)  {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}