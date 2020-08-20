/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TACHSTCK Problem
*   Problem Link:- https://www.codechef.com/problems/TACHSTCK
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
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
    int n, d, x, count = 0;
    vector<int> l;

    // * Accepting the number of sticks and maximum acceptable difference
    cin>>n>>d;

    // * Accepting the length of each stick one by one and adding it to a vector
    for(int i=0; i<n; i++) {
        cin>>x;
        l.push_back(x);
    }

    // * If there is only one stick, display 0
    if(n==1) {
        cout<<"0"<<endl;
        return 0;
    }

    // * Sort the array consisting of length of sticks
    sort(l.begin(), l.end());

    // * Calculating the maximum possible pairs of chopsticks
    for(int i=1; i<n; i++) {
        if(l[i]-l[i-1] <= d) {
            count++;
            i++;
        }
    }

    // * Display the maximum number of pairs of chopsticks
    cout<<count;
}