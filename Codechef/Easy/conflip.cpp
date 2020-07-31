/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CONFLIP Problem
*   Problem Link:- https://www.codechef.com/problems/CONFLIP
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
	int numberOfTestCases, initialStateOfCoins, numberOfCoins, finalStateOfCoins, numberOfGames;

    // * Accepting the number of test cases
	cin>>numberOfTestCases;

    // * Executing each test case one by one
	while(numberOfTestCases--) {

        // * Accepting the number of games in the current test case
	    cin>>numberOfGames;

        // * Executing each game one by one
	    while(numberOfGames--) {

            /*
            *   Accepting the initial state of coins,
            *   number of coins and the final state of coins for the current game
            */
    	    cin>>initialStateOfCoins>>numberOfCoins>>finalStateOfCoins;

            /*
            *   If the initial state of coins is not equal to the
            *   final state of coins and the number of coins are odd,
            *   the number of coins in the final state will be (numberofCoins/2) + 1
            */
    	    if(
                initialStateOfCoins!=finalStateOfCoins &&
                numberOfCoins&1
            ) {
    	        cout<<numberOfCoins/2+1<<endl;
    	    }

            /*
            *   Otherwise, the number of coins
            *   in the final state will be numberOfCoins/2
            */
            else {
    	        cout<<numberOfCoins/2<<endl;
    	    }
	    }
	}

	return 0;
}