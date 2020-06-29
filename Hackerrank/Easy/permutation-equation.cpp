/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Sequence Equation problem
*   Problem Link:- https://www.hackerrank.com/challenges/permutation-equation/problem
*/
vector<int> permutationEquation(vector<int> p) {

    // * Initializing Variables
    vector<int> finalVector;
    int reverseArr[51];

    // * Storing the index of p with respect to it's value
    for(int i=0; i<p.size(); i++) {
        reverseArr[p[i]] = i+1;
    }

    /*
    *   Finding the value of y using the reverse array
    *   and storing it in the final vector
    */
    for(int i=1; i<=p.size(); i++) {
        finalVector.push_back(reverseArr[reverseArr[i]]);
    }

    // * Returning the final vector
    return finalVector;
}