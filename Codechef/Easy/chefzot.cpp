/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHEFZOT Problem
*   Problem Link:- https://www.codechef.com/problems/CHEFZOT
*	Website:- www.programmingvidya.com
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

    // * Initializing variables
    int n, a, currentLength = 0, maxLength = 0;

    // * Accepting the number of elements
    cin>>n;

    /*
    *   Accepting each element one by one and calculating
    *   the maximum length of subarray with non-zero product
    */
    while(n--) {

        // * Accepting the current element
        cin>>a;

        /*
        *   if the current element is 0,
        *   calculate the length of subarray encountered till now
        *   and update the maximum length if required. Also,
        *   initialize the length of next subarray to 0
        */
        if(a==0) {
            maxLength = max(currentLength, maxLength);
            currentLength = 0;
        }

        /*
        *   Otherwise, increment the length of current
        *   subarray by 1
        */
        else {
            currentLength++;
        }
    }

    /*
    *   Comparing the maximum length with the length of
    *   last subarray and updating the maximum length if required
    */
    maxLength = max(currentLength, maxLength);

    // * Displaying the maximum length
    cout<<maxLength;
}