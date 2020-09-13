/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TREEROOT Problem
*   Problem Link:- https://www.codechef.com/problems/TREEROOT
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Initializing the variables
    int numberOfTestCases, numberOfNodes, nodeId, sumOfChildNodes, root;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        root = 0;

        // * Accepting the number of nodes in a tree
        cin>>numberOfNodes;

        /*
        *   Accepting id of each node in the tree
        *   and sum of it's child nodes. Calculating the root node
        */
        while(numberOfNodes--) {
            cin>>nodeId>>sumOfChildNodes;
            root += nodeId - sumOfChildNodes;
        }

        // * Displaying the root node
        cout<<root<<endl;
    }
}