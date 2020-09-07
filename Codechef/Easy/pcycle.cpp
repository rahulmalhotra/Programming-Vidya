/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PCYCLE Problem
*   Problem Link:- https://www.codechef.com/problems/PCYCLE
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <vector>
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
    int n, a[1001], totalCycles = 0;
    vector<int> cycles;
    bitset<1001> visited;

    // * Accepting the length of permutation
    cin>>n;

    // * Accepting the numbers
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }

    // * Iterating the numbers one by one
    for(int i=1; i<=n; i++) {

        // * If we haven't visited the number before
        if(!visited.test(i)) {

            // * Loop until we get back to the starting index
            while(!visited.test(i)) {

                // * Add the current index to the current cycle
                cycles.push_back(i);

                // * Mark the current index as visited
                visited.set(i);

                // * Update the current index
                i = a[i];
            }

            /*
            *   Once we've reached the starting index again,
            *   increment the number of cycles by 1
            */
            totalCycles++;

            // * Push the starting index again to the current cycle
            cycles.push_back(i);

            // * Push 0 to the cycles vector to specify the current cycle end
            cycles.push_back(0);
        }
    }

    // * Display the total number of cycles
    cout<<totalCycles<<endl;

    // * Display the cycles one by one
    for(int i=0; i<cycles.size(); i++) {
        if(cycles[i] == 0) {
            cout<<endl;
        } else {
            cout<<cycles[i]<<" ";
        }
    }
}