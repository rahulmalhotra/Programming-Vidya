/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Circular Array Rotation problem
*   Problem Link:- https://www.hackerrank.com/challenges/circular-array-rotation/problem
*/
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {

    // * Initializing variables
    vector<int> result;
    int n = a.size();

    // * Considering each query index one by one
    for(int q=0; q<queries.size(); q++) {

        /*
        *   Final starting index after k rotations
        *   will be:- n-(k%n). For query q, the element
        *   will be at index (queries[q] + <final starting index>) % n
        *   Therefore final resultant index:- (queries[q]+n-(k%n))%n
        *   Pushing the value at final resultant index into result vector
        */
        result.push_back(a[(queries[q]+n-(k%n))%n]);
    }

    // * Returning the result vector
    return result;
}