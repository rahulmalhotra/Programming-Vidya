/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TSORT Problem
*   Problem Link:- https://www.codechef.com/problems/TSORT
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
    int n, frequency[1000005] = {0}, x;

    // * Accepting the number of numbers
    cin>>n;

    // * Accepting each number one by one and setting up it's frequency
    while(n--) {
        cin>>x;
        frequency[x]++;
    }

    // * Displaying the numbers in ascending order using the frequency array
    for(int i=0; i<=1000000; i++) {
        while(frequency[i]--) {
            cout<<i<<endl;
        }
    }
}