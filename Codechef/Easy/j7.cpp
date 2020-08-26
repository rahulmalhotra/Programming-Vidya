/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef J7 Problem
*   Problem Link:- https://www.codechef.com/problems/J7
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
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
    int numberOfTestCases, p, s;
    float volume, height;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while (numberOfTestCases--)
    {
        // * Accepting the length of wire and the area of paper
        cin>>p>>s;

        // * Calculating the value of height for maximum possible volume
        height = (p - sqrt(p*p - 24*s)) / 12;

        // * Calculating the maximum volume by using the formula in terms of height, p and s
        volume = height*s/2 - height*height*p/4 + height*height*height;

        // * Displaying the value of maximum volume upto 2 decimal places
        cout<<fixed<<setprecision(2)<<volume<<endl;
    }
}