/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Non-Divisible Subset problem
*   Problem Link:- https://www.hackerrank.com/challenges/non-divisible-subset/problem
*   Concept:-
*       If sum of two numbers is divisible by k,
*       then, the sum of their remainders,
*       when those numbers are divided by k, is equal to k
*/
int nonDivisibleSubset(int k, vector<int> s) {

    // * Initializing variables
    int count[101] = {0}, resultSetCount = 0;

    /*
    *   If k is 1, that means all elements will be divisible by k
    *   as well as the sum of any 2 elements will also be
    *   divisible by k, therefore, we can say that maximum
    *   number of elements in subset = 1
    */
    if(k==1) {
        return 1;
    }

    /*
    *   Forming the frequency array for remainders,
    *   when the numbers are divided by k
    */
    for(int i=0; i<s.size(); i++) {
        count[s[i]%k]++;
    }

    /*
    *   If the numbers with remainder 0 are more than 0,
    *   we can only take one of them
    */
    if(count[0]>0) {
        resultSetCount++;
    }

    /*
    *   If k is odd, loop from 1 till k/2 and adding
    *   the maximum count of numbers by comparing
    *   the remainders k and k-i
    */
    if(k&1) {
        for(int i=1; i<=k/2; i++) {
            resultSetCount += max(count[i], count[k-i]);
        }
    }

    /*
    *   If k is even, loop from 1 till (k/2 - 1) and adding
    *   the maximum count of numbers by comparing
    *   the remainders k and k-i
    */
    else {
        for(int i=1; i<k/2; i++) {
            resultSetCount += max(count[i], count[k-i]);
        }

        /*
        *   If the numbers with remainder k/2 are more than 0,
        *   we can only take one of them in the subset
        */
        if(count[k/2]>0) {
            resultSetCount++;
        }
    }

    // * Returning the final subset
    return resultSetCount;
}