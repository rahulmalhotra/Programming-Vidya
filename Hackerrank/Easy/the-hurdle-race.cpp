/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank The Hurdle Race problem
*   Problem Link:- https://www.hackerrank.com/challenges/the-hurdle-race/problem
*/
int hurdleRace(int k, vector<int> height) {

    // * Initializing variables
    int maxHeight = 0;

    // * Calculating the Maximum Height
    for(int i=0; i<height.size(); i++) {
        maxHeight = max(maxHeight, height[i]);
    }

    /*
    *   If maximum height is more than the height dan can jump,
    *   number of doses dan require = max height - height dan can jump.
    *   Otherwise, number of doses dan require = 0
    */
    return maxHeight > k ? maxHeight - k : 0;
}