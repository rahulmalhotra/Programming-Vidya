/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Picking Numbers Problem
*   Problem Link:- https://www.hackerrank.com/challenges/picking-numbers/problem
*/
int pickingNumbers(vector<int> a) {

    // * Initializing the variables
    int freq[100] = {0}, longestArrayLength = 0;

    // * Setting up the frequency array
    for(int i=0; i<a.size(); i++) {
        freq[a[i]]++;
    }

    /*
    *   Longest Array Length can be defined as the length
    *   of the array that consist of two consecutive
    *   numbers, sum of whose frequency is maximum
    */
    for(int i=0; i<99; i++) {
        longestArrayLength = max(longestArrayLength, freq[i] + freq[i+1]);
    }

    // * Returning the longest array length
    return longestArrayLength;
}