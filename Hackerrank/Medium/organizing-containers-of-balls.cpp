/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Organizing Containers of Balls problem
*   Problem Link:- https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
*/
string organizingContainers(vector<vector<int>> container) {

    // * Initializing variables
    int sumR, sumC;
    vector<int> rowSum, colSum;

    /*
    *   Calculating the row sum and column sum
    *   for each row and column, following the diagonal from
    *   top left to bottom right
    */
    for(int i=0; i<container.size(); i++) {

        /*
        *   Initializing row sum and column sum to 0
        *   while considering every new row and column
        */
        sumR = 0;
        sumC = 0;

        // * Calculating the row sum and column sum
        for(int j=0; j<container[i].size(); j++) {
            sumR += container[i][j];
            sumC += container[j][i];
        }

        // * Adding row sum and column sum to rowSum and colSum vectors
        rowSum.push_back(sumR);
        colSum.push_back(sumC);
    }

    /*
    *   Sorting the rowSum and colSum vectors
    *   This sorting is required because, we're given that any container
    *   can contain any type of ball, maintaining that all the balls are
    *   of same type in a single container. In simple words, it's not necessary
    *   that container of type 0 should contain all the balls of type 0 only,
    *   it can contain all balls of type 1 or any other type as well
    */
    sort(rowSum.begin(), rowSum.end());
    sort(colSum.begin(), colSum.end());

    /*
    *   Checking, if the elements in sorted rowSum vector are equal
    *   to the elements in sorted colSum vector at the same index.
    *   If at any index, they're not equal, return "Impossible"
    */
    for(int i=0; i<rowSum.size(); i++) {
        if(rowSum[i]!=colSum[i]) {
            return "Impossible";
        }
    }

    // * If all the elements are equal, return "Possible"
    return "Possible";
}