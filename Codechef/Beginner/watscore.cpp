/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef WATSCORE Problem
*   Problem Link:- https://www.codechef.com/problems/WATSCORE
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, totalNumberOfSubmissions, scores[9] = {0}, pi, si, totalScore;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing the value of total score to 0 for current test case
        totalScore = 0;

        // * Accepting the total number of submissions
        cin>>totalNumberOfSubmissions;

        // * Looping the total number of submissions
        while(totalNumberOfSubmissions--) {

            /*
            *   Accepting the problem number and the score for that problem
            *   for the current submission
            */
            cin>>pi>>si;

            /*
            *   If problem number is between 1 and 8
            *   and the score stored for that problem is less than the current score,
            *   update the score for that problem in the scores array
            */
            if(
                pi<=8 &&
                pi>=1 &&
                si>scores[pi]
            ) {
                scores[pi] = si;
            }
        }

        /*
        *   Calculating the total score by adding the score of each problem
        *   Also, initializing the score of each problem to 0 for next test case
        */
        for(int i=1; i<=8; i++) {
            totalScore += scores[i];
            scores[i] = 0;
        }

        // * Displaying the total score for current test case
        cout<<totalScore<<endl;
    }
}