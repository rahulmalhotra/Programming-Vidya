/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef SPLST Problem
*   Problem Link:- https://www.codechef.com/problems/SPLST
*/
#include <iostream>
#include<cstring>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, a, b, c, x, y, minimum = 999;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the value of a, b, c, x and y for each test case
        cin>>a>>b>>c>>x>>y;

        // * Finding the minimum element out of a, b and c
        minimum = min(a, b);
        minimum = min(minimum, c);

        /*
        *   If x is less than minimum or y is less than minimum,
        *   Answer is "NO" as we cannot reduce the stones in any of
        *   a, b or c piles.
        */
        if(x<minimum || y<minimum) {
            cout<<"NO"<<endl;
        }
        /*
        *   If Sum of stones in all piles = Sum of stones required after distribution
        *   Answer is "YES"
        */
        else if((a+b+c) == (x+y)) {
            cout<<"YES"<<endl;
        }
        // * Otherwise, Answer is "NO"
        else {
            cout<<"NO"<<endl;
        }
    }
}