/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RESQ Problem
*   Problem Link:- https://www.codechef.com/problems/RESQ
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

    // * Initializing variables
    int numberOfTestCases, n, i;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of cupcakes for the current test case i.e. total area
        cin>>n;

        // * Calculating the square root of total area
        for(i=0; i*i<n; i++);

        // * If the number of cupcakes is a perfect square, display 0
        if(i*i==n) {
            cout<<"0"<<endl;
        }

        /*
        *   Otherwise, calculate the factors i.e. length of sides of rectangle
        *   and display their difference. If one side is 'j', other side will be 'n/j'
        */
        else {
            for(int j=i-1; j>=1; j--) {
                if(n%j==0) {
                    cout<<(n/j)-j<<endl;
                    break;
                }
            }
        }
    }
}