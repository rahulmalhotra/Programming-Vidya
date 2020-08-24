/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef SPCANDY Problem
*   Problem Link:- https://www.codechef.com/problems/SPCANDY
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
    long numberOfTestCases, numberOfCandies, numberOfStudents;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while (numberOfTestCases--)
    {
        /*
        *   Accepting the number of candies and
        *   the number of students in the current test case
        */
        cin>>numberOfCandies>>numberOfStudents;

        /*
        *   Displaying the number of candies each student will get
        *   and the number of candies, the teacher will get
        *   for the current test case
        */
        if(numberOfStudents == 0) {
            cout<<"0 "<<numberOfCandies<<endl;
        } else {
            cout<<numberOfCandies/numberOfStudents<<" "<<numberOfCandies%numberOfStudents<<endl;
        }
    }
}