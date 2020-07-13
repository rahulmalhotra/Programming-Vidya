/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Beautiful Triplets problem
*   Problem Link:- https://www.hackerrank.com/challenges/beautiful-triplets/problem
*/

int beautifulTriplets(int d, vector<int> arr) {

    // * Initializing variables
    int numberOfBeautifulTriplets = 0;
    unordered_map<int, int> freqMap;

    /*
    *   Forming the frequency map and counting the beautiful triplets.
    *   Each number will form a*b beautiful triplets where
    *   a and b are the frequency of previous 2 numbers in the triplet
    */
    for(int i=0; i<arr.size(); i++) {
        freqMap[arr[i]]++;
        numberOfBeautifulTriplets += freqMap[arr[i]-d]*freqMap[arr[i]-2*d];
    }

    // * Returning the number of beautiful triplets
    return numberOfBeautifulTriplets;
}