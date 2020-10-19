/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef AND Problem
*   Problem Link:- https://www.codechef.com/problems/AND
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <math.h>
using namespace std;

int main() {

	/*
    *   Initializing variables
    *   size is the maximum number of bits any number can have in the range
    *   i.e. the number of bits in 10^9
    */
    int n, a[1000000], size = ceil(log2(1000000000)), count;
    long long int sum = 0;

    // * Accepting the total number of integers
    cin>>n;

    // * Accepting each integer one by one
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    // * Calculating the sum
    for(int i=0; i<size; i++) {

        // * Initializing count to 0
        count = 0;

        /*
        *   Checking the last bit of each number, if it's set,
        *   increment count by 1 and updating the number
        *   by right shifting it by 1
        */
        for(int j=0; j<n; j++) {
            count += a[j]&1;
            a[j] = a[j]>>1;
        }

        /*
        *   Adding the total occurrences of 2^i to the final sum, in other words:-
        *   Current sum = (total number of ways by which the current set bit is added to the answer) * (2^i)
        *   where 2^i = the value of current set bit
        */
        sum += ((long long int) (count)*(count - 1) / 2) * pow(2,i);
    }

    // * Displaying the total sum
    cout<<sum;

	return 0;
}