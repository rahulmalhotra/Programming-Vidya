/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHEFA Problem
*   Problem Link:- https://www.codechef.com/problems/CHEFA
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <queue>
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

    // * Initializing variables
    int numberOfTestCases, numberOfPiles, numberOfStones, count;
    long long int maximumStonesChefCanRemove;
    priority_queue<int> maxHeap;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of piles for the current test case
        cin>>numberOfPiles;

        // * Storing the number of stones in each pile in a max heap
        while(numberOfPiles--) {
            cin>>numberOfStones;
            maxHeap.push(numberOfStones);
        }

        /*
        *   Initializing count to 1 and
        *   total stones chef can remove to 0
        *   for the current test case
        */
        count = 1;
        maximumStonesChefCanRemove = 0;

        /*
        *   Calculating the maximum number of stones, chef can remove
        *   if he takes the first turn
        */
        while(!maxHeap.empty()) {
            if(count&1) {
                numberOfStones = maxHeap.top();
                maximumStonesChefCanRemove += numberOfStones;
            }
            maxHeap.pop();
            count++;
        }

        /*
        *   Displaying the maximum number of stones
        *   chef can remove for the current test case
        */
        cout<<maximumStonesChefCanRemove<<endl;
    }
}