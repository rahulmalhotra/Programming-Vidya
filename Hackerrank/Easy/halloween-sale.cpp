/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Halloween Sale Problem
*   Problem Link:- https://www.hackerrank.com/challenges/halloween-sale/problem
*/
int howManyGames(int p, int d, int m, int s) {

    // * Initializing variables
    int numberOfGames = 0, moneySpent = p, currentPrice;

    // * Iterating while money spend <= money in wallet
    while(moneySpent<=s) {

        // * Updating the base price
        p -= d;

        // * Updating the price of the current video game
        currentPrice = p>m ? p : m;

        // * Updating the money spent
        moneySpent += currentPrice;

        // * Increasing the count of number of games bought by 1
        numberOfGames++;
    }

    // * Returning the number of games bought
    return numberOfGames;
}