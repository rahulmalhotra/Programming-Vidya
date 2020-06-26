/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Viral Advertising problem
*   Problem Link:- https://www.hackerrank.com/challenges/strange-advertising/problem
*/
int viralAdvertising(int n) {

    // * Initializing Variables
    int totalLikes = 0, numberOfShares = 5, currentLikes = 0;

    /*
    *   Calculating the likes on each day,
    *   adding them to the total likes,
    *   and updating the number of shares for next day
    */
    for(int i=0; i<n; i++) {
        currentLikes = numberOfShares/2;
        totalLikes += currentLikes;
        numberOfShares = currentLikes*3;
    }

    // * Returning the total likes
    return totalLikes;
}