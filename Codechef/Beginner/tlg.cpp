/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TLG Problem
*   Problem Link:- https://www.codechef.com/problems/TLG
*   Website:- www.programmingvidya.com
*/
#include<iostream>
#include<stdio.h>
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
    int n, s, t, p1Score = 0, p2Score = 0, currentMaximumScore = 0, maximumScore = 0, currentWinner, winner;

    // * Accepting the number of rounds
    cin>>n;

    // * Executing each round one by one
    while(n--) {

        // * Accepting the score of player 1 and player 2
        cin>>s>>t;

        // * Calculating the cumulative score of player 1 and player 2
        p1Score += s;
        p2Score += t;

        /*
        *   Calculating the current maximum score
        *   and the current winner
        */
        if(p1Score>p2Score) {
            currentMaximumScore = p1Score - p2Score;
            currentWinner = 1;
        } else {
            currentMaximumScore = p2Score - p1Score;
            currentWinner = 2;
        }

        /*
        *   If current maximum score is more than
        *   the maximum score encountered till now,
        *   update the maximum score and the winner
        */
        if(currentMaximumScore > maximumScore) {
            maximumScore = currentMaximumScore;
            winner = currentWinner;
        }
    }

    // * Displaying the winner and the maximum score
    cout<<winner<<" "<<maximumScore;
}