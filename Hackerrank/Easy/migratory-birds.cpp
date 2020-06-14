/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Migratory Birds Problem
*   Problem Link:- https://www.hackerrank.com/challenges/migratory-birds/problem
*/

int migratoryBirds(vector<int> arr) {

    // * Initializing Variables
    int freq[6] = {0}, maxFreq = 0, maxFreqIndex = 0;

    /*
    *   For each type encountered in array,
    *   incrementing the frquency of that type by 1
    */
    for(int i=0; i<arr.size(); i++) {
        freq[arr[i]]++;
    }

    // * Iterating the frequency array
    for(int i=1; i<=5; i++) {

        /*
        *   If current frequency is more than maximum frequency,
        *   updating the maximum frequency and the maximum frequency index
        */
        if(freq[i]>maxFreq) {
            maxFreq = freq[i];
            maxFreqIndex = i;
        }
    }

    // * Returning the maximum frequency index
    return maxFreqIndex;
}