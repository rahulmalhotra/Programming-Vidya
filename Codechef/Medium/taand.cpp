/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TAAND Problem
*   Problem Link:- https://www.codechef.com/problems/TAAND
*	Website:- www.programmingvidya.com
*/

#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;

bitset<300000> valid;

/*
*   This function is used to calculate the value of maximum AND
*   and return the result
*/
long long int maximumAnd(int a[], int n, int index) {

    // * If the index of bit is -1, return 0
    if(index==-1) {
        return 0;
    }

    // * Initializing count and result to 0
    long long int count = 0, result = 0;

    /*
    *   Checking all valid integers in the array a,
    *   if the current integer has the bit at index set,
    *   incrementing the count
    */
    for(int i=0; i<n; i++) {
        if(!valid.test(i)) {
            if(a[i] & (1<<index)) {
                count++;
            }
        }
    }

    /*
    *   If count >= 2, adding the value of the bit at index
    *   to the result as we're going to consider that set bit
    *   in the result. Also, marking all the other integers as
    *   invalid where the bit at index is not set
    */
    if(count>=2) {
        result += (1<<index);
        for(int i=0; i<n; i++) {
            if((a[i] & (1<<index)) == 0) {
                valid.set(i);
            }
        }
    }

    // * Returning the result
    return result + maximumAnd(a, n, index-1);
}


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
    int n, a[300000];

    // * Accepting the number of integers
    cin>>n;

    // * Accepting the integers of array one by one
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    // * Displaying the value of maximum AND
    cout<<maximumAnd(a, n, 30);

	return 0;
}