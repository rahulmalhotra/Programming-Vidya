/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ANUBTG Problem
*   Problem Link:- https://www.codechef.com/problems/ANUBTG
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
    int numberOfTestCases, numberOfItems, cost, totalCost;
    priority_queue<int> pq;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of items in the current test case
        cin>>numberOfItems;

        // * Initializing total cost to 0 for the current test case
        totalCost = 0;

        // * Accepting and storing the cost of each item in a max heap
        for(int i=0; i<numberOfItems; i++) {
            cin>>cost;
            pq.push(cost);
        }

        /*
        *   Calculating the total cost by following the steps below:-
        *   1. Pop the top two items from the max heap and add their cost
        *   2. Skip the next two items
        */
        for(int i=0; i<numberOfItems; i++) {
            if(i%4==0) {
                totalCost += pq.top();
                pq.pop();
                if(!pq.empty()) {
                    totalCost += pq.top();
                    pq.pop();
                    i++;
                }
            } else {
                pq.pop();
            }
        }

        // * Displaying the total cost for the current test case
        cout<<totalCost<<endl;
    }
}