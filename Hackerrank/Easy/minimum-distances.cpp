/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Minimum Distances Problem
*   Problem Link:- https://www.hackerrank.com/challenges/minimum-distances/problem
*/
int minimumDistances(vector<int> a) {

    // * Initializing variables
    unordered_map<int, int> indexMap;
    int minDist = 100001;

    // * Considering each value in the array one by one
    for(int i=0; i<a.size(); i++) {

        /*
        *   If we've previously encountered this value,
        *   calculate the distance. If it's smaller than the current
        *   minimum distance, update the minimum distance
        */
        if(indexMap[a[i]]!=0) {
            minDist = min(minDist, (i+1) - indexMap[a[i]]);
        }

        /*
        *   Store/Update the index of the current value in the map.
        *   We're adding one to every index before storing
        *   because the default value of any key
        *   in the map is 0 and the index can be zero as well
        */
        indexMap[a[i]] = i+1;
    }

    // * If the minimum distance is updated, returning that otherwise returning -1
    return minDist == 100001 ? -1 : minDist;
}