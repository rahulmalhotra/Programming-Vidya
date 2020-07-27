/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CIELAB Problem
*   Problem Link:- https://www.codechef.com/problems/CIELAB
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
    int a, b, diff, lastDigit;

    // * Accepting integers a and b
    cin>>a>>b;

    // * Calculating the difference between a and b
    diff = a-b;

    /*
    *   Getting the last digit of difference between a and b.
    *   If we divide any number by 10, the last digit
    *   of the number will be given in the remainder
    */
    lastDigit = diff%10;

    /*
    *   If the last digit of difference is equal to 9,
    *   subtract 1 from the difference to make last digit different
    *   as the number of digits in the output should be same as in
    *   the original difference
    */
    if(lastDigit==9) {
        cout<<diff-1;
    }

    /*
    *   Otherwise, add 1 to the difference to make the last digit
    *   different in the output. The number of digits in the output
    *   will remain the same as of original difference
    */
    else {
        cout<<diff+1;
    }

	return 0;
}