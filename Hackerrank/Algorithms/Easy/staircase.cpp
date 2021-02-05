/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Staircase problem
*   Problem Link:- https://www.hackerrank.com/challenges/staircase/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {

    // * Printing n rows
    for(int i=0; i<n; i++) {

        // * Printing n-i-1 spaces for the current row
        for(int j=n-1; j>i; j--) {
            cout<<" ";
        }

        // * Printing i+1 # for the current row
        for(int j=i; j>=0; j--) {
            cout<<"#";
        }

        // * Adding a new line at the end of the current row
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
