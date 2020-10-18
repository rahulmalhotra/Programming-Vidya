/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TADELIVE Problem
*   Problem Link:- https://www.codechef.com/problems/TADELIVE
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {

	// * Initializing variables
    int n, x, y, a[100000], b[100000], valueA = 0, valueB = 0, total = 0;
    priority_queue<pair<int, int> > pq;

    // * Accepting the values
    cin>>n>>x>>y;

    // * Accepting the tips for Andy
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    // * Accepting the tips for Bob
    for(int i=0; i<n; i++) {
        cin>>b[i];
    }

    /*
    *   Forming a max heap consisting of loss
    *   in the tip of Andy and Bob for each order
    */
    for(int i=0; i<n; i++) {
        pq.push({ abs(a[i]-b[i]), i });
    }

    // * Considering each order one by one
    for(int i=0; i<n; i++) {

        /*
        *   Finding the value of Andy's tip and Bob's tip
        *   for current order sorted by maximum loss
        */
        valueA = a[pq.top().second];
        valueB = b[pq.top().second];

        // * If both Andy and Bob can take the order
        if(x && y) {

            // * If Andy's tip is more, give the order to Andy
            if(valueA > valueB) {
                total += valueA;
                x--;
            }

            // * If Bob's tip is more, give the order to Bob
            else if(valueA < valueB) {
                total += valueB;
                y--;
            }

            /*
            *   If Both the tips are equal,
            *   if Andy can take more orders as compared to Bob,
            *   give the order to Andy
            */
            else if(x > y) {
                total += valueA;
                x--;
            }

            // * Otherwise, give the order to Bob
            else {
                total += valueB;
                y--;
            }
        }

        /*
        *   If Andy can take more orders,
        *   give the current order to Andy
        */
        else if(x) {
            total += valueA;
            x--;
        }

        // * Otherwise, give the current order to Bob
        else {
            total += valueB;
            y--;
        }

        // * Pop the top element from the max heap
        pq.pop();
    }

    // * Displaying the maximum tip money, Andy and Bob can receive
    cout<<total<<endl;

	return 0;
}