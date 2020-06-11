/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Breaking the Records Problem
*   Problem Link:- https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
*/
vector<int> breakingRecords(vector<int> scores) {

    /*
    *   Initializing minMaxVector elements to 0,
    *   minScore and maxScore to the first score
    */
    vector<int> minMaxVector(2, 0);
    int minScore = scores[0], maxScore = scores[0];

    /*
    *   Iterating all scores one by one, starting from 2nd score.
    *   If score is greater than maxScore, updating the maxScore
    *   as well as the count in minMaxVector for maximum score.
    *   Similarly, if score is less than minScore, updating the minScore
    *   as well as the count in minMaxVector for minimum score
    */
    for(int i=1; i<scores.size(); i++) {
        if(scores[i]>maxScore) {
            maxScore = scores[i];
            minMaxVector[0]++;
        } else if(scores[i]<minScore) {
            minScore = scores[i];
            minMaxVector[1]++;
        }
    }

    // * Returning the minMaxVector
    return minMaxVector;
}