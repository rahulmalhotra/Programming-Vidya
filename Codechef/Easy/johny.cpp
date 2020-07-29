/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef JOHNY Problem
*   Problem Link:- https://www.codechef.com/problems/JOHNY
*/
#include <iostream>
#include <algorithm>
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
    int t, n, k, a[100];

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    while(t--) {

        // * Accepting the number of songs in the playlist
        cin>>n;

        // * Accepting the length of each song
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        // * Accepting the position of "Uncle Johny" song in the playlist
        cin>>k;

        // * Getting the length of "Uncle Johny" song and updating variable k
        k = a[k-1];

        // * Sorting the playlist
        sort(a, a+n);

        /*
        *   Finding the "Uncle Johny" song in the sorted playlist
        *   and displaying it's position
        */
        for(int i=0; i<n; i++) {
            if(k==a[i]) {
                cout<<i+1<<endl;
                break;
            }
        }
    }

	return 0;
}