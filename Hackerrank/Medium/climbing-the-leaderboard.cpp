/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Climbing the Leaderboard problem
*   Problem Link:- https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
*/
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    // * Initializing Variables
    vector<int> aliceRanks;
    int aliceSize = alice.size(), scoresSize = scores.size(), prevScore = -1, j = 0, currentRank = 1;

    // * Iterating alice scores from highest to lowest
    for(int i=aliceSize-1; i>=0; i--) {

        /*
        *   Iterating leaderboard scores from highest to lowest
        *   until the below condition satisfy:-
        *   1. Alice's score is less than current score
        *   2. We've not reached the end of leaderboard scores
        */
        while(
            (alice[i] < scores[j]) &&
            (j<scoresSize)
        ) {

            // * If the current score hasn't appeared before
            if(prevScore != scores[j]) {

                /*
                *   Setting up the previous score with
                *   the value of current score and
                *   incrementing the value of current rank by 1
                */
                prevScore = scores[j];
                currentRank++;
            }

            /*
            *   Incrementing the index of leaderboard scores.
            *   Note that we're not re-setting the leaderboard scores
            *   index for next iteration
            */
            j++;
        }

        // * Inserting the current rank at the beginning of alice ranks array
        aliceRanks.insert(aliceRanks.begin(), currentRank);
    }

    // * Returning the alice ranks array
    return aliceRanks;
}