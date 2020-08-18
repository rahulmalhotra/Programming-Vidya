/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FCTRL2 Problem
*   Problem Link:- https://www.codechef.com/problems/FCTRL2
*   Website:- www.programmingvidya.com
*   Note:- Remove the comments before submitting to Codechef
*          as the source limit is 2000 bytes
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
    int numberOfTestCases, factorial[160] = {0}, n;
    factorial[0] = 1;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number
        cin>>n;

        // * Initializing index, carry, digit and size variables
        int i, carry, digit, size = 1;

        // * Considering each number in factorial multiplicaion one by one
        while(n--) {

            // * Initializing carry and array index to 0
            carry = 0;
            i=0;

            /*
            *   Multiplying the number n with array and storing the
            *   result of multiplication back in array.
            *   Note that each element of array consist of
            *   one digit of multiplication result
            */
            do {
                digit = factorial[i] * (n+1) + carry;
                factorial[i++] = digit%10;
                carry = digit/10;
                size--;
            } while(carry!=0 || size>0);

            // * Updating the size of the resultant array
            size = i;
        }

        /*
        *   Displaying the array elements i.e. the factorial of number n
        *   and reinitializing it for next test case
        */
        while(size--) {
            cout<<factorial[size];
            factorial[size] = 0;
        }
        factorial[0] = 1;

        // * Adding a new line before executing the next test case
        cout<<endl;
    }
}