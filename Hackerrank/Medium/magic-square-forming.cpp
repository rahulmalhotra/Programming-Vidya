/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Forming a Magic Square Problem
*   Problem Link:- https://www.hackerrank.com/challenges/magic-square-forming/problem
*/
int formingMagicSquare(vector<vector<int>> s) {

    // * Initializing Variables
    int minCost = 81, currentCost;

    /*
    *   There are a total of 8 possible Magic Matrices
    *   which we've stored below
    */
    int magicMatrices[8][3][3] = {
        {{4,9,2}, {3,5,7}, {8,1,6}},
        {{8,3,4}, {1,5,9}, {6,7,2}},
        {{6,1,8}, {7,5,3}, {2,9,4}},
        {{2,7,6}, {9,5,1}, {4,3,8}},
        {{4,3,8}, {9,5,1}, {2,7,6}},
        {{2,9,4}, {7,5,3}, {6,1,8}},
        {{6,7,2}, {1,5,9}, {8,3,4}},
        {{8,1,6}, {3,5,7}, {4,9,2}}
    };

    // * Considering each Magic Matrix one by one
    for(int i=0; i<8; i++) {

        /*
        *   Initializing cost to covert given matrix
        *   into current magic matrix with zero
        */
        currentCost = 0;

        /*
        *   Calculating the cost to convert given matrix
        *   to current magic matrix
        */
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                currentCost += abs(s[j][k] - magicMatrices[i][j][k]);
            }
        }

        /*
        *   Updating the minimum cost, if the current cost
        *   is less than the minimum cost till now
        */
        minCost = min(minCost, currentCost);
    }

    // * Returning the minimum cost
    return minCost;
}