/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Divisible Sum Pairs Problem
*   Problem Link:- https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
*/

int divisibleSumPairs(int n, int k, vector<int> ar) {

    /*
    *   Initializing count to 0, creating a
    *   frequency array with k elements and
    *   initializing all elements to 0
    */
    int count=0;
    vector<int> freq(k,0);

    /*
    *   Iterating the array.
    *   For each element in the array, dividing it by k to find the remainder,
    *   If remainder is 0, compliment will also be 0, otherwise,
    *   compliment will be k - remainder.
    *   Adding the current frequency of compliment in the count,
    *   because the remainder will make pairs with
    *   all the compliments that have occured before.
    *   Incrementing the frequency of remainder by 1 for future use.
    */
    for(int i=0; i<n; i++) {
        int remainder = ar[i]%k;
        int compliment = remainder == 0 ? remainder : k - remainder;
        count += freq[compliment];
        freq[remainder]++;
    }

    // * Returning the count
    return count;
}