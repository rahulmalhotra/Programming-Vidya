/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CNOTE Problem
*   Problem Link:- https://www.codechef.com/problems/CNOTE
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

    // * Initializing the variables
	int numberOfTestCases, totalNumberOfPagesRequiredForPoetry, numberOfPagesLeftInOldNotebook, numberOfRubles, numberOfNewNotebooks, numberOfPagesInNewNotebook, priceOfNewNotebook;
    bool luckyChef;

    // * Accepting the number of test cases
	cin>>numberOfTestCases;

    // * Executing each test case one by one
	while(numberOfTestCases--) {

        // * Initializing luckyChef variable to false for the current test case
        luckyChef = false;

        /*
        *   Accepting the following information for the current test case:-
        *   1. Total number of pages required for poetry
        *   2. Number of pages left in old notebook
        *   3. Number of rubles left with chef
        *   4. Number of new notebooks displayed by shopkeeper
        */
	    cin>>totalNumberOfPagesRequiredForPoetry>>numberOfPagesLeftInOldNotebook>>numberOfRubles>>numberOfNewNotebooks;

        // * Executing case for each new notebook
	    while(numberOfNewNotebooks--) {

            // * Accepting the number of pages in new notebook and price of new notebook
            cin>>numberOfPagesInNewNotebook>>priceOfNewNotebook;

            /*
            *   If the sum of number of pages left in old notebook and
            *   number of pages in new notebook is greater than or equal to the
            *   total number of pages required by chef for poetry. Also, if the price
            *   of new notebook is less than or equal to the number of rubles chef has,
            *   set the boolean variable luckyChef to true. Chef can complete his poetry,
            *   if this condition is satisfied by any new notebook displayed to chef by shopkeeper
            */
            if(
                (numberOfPagesLeftInOldNotebook + numberOfPagesInNewNotebook) >= totalNumberOfPagesRequiredForPoetry &&
                priceOfNewNotebook <= numberOfRubles
            ) {
                luckyChef = true;
            }
	    }

        /*
        *   If luckyChef boolean variable is true,
        *   display "LuckyChef" for current test case.
        *   Otherwise, display "UnluckyChef" for current test case
        */
        if(luckyChef) {
            cout<<"LuckyChef"<<endl;
        } else {
            cout<<"UnluckyChef"<<endl;
        }
	}

	return 0;
}