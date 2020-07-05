/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Equalize the Array problem
*   Problem Link:- https://www.hackerrank.com/challenges/equality-in-a-array/problem
*/
int equalizeArray(vector<int> arr) {

    // * Initializing variables
    int freq[101] = {0}, maxFreq = 0, arrSize = arr.size();

    // * Calculating the frequency array
    for(int i=0; i<arrSize; i++) {
        freq[arr[i]]++;
    }

    // * Finding the maximum frequency from the frequency array
    for(int i=1; i<=100; i++) {
        maxFreq = max(maxFreq, freq[i]);
    }

    /*
    *   Returning the minimum number of operations required to equalize the array,
    *   minimum number of operations = size of array - maximum frequency
    */
    return arrSize-maxFreq;
}