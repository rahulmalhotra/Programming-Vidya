/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ADAKING Problem (July Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JULY20B/problems/ADAKING
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
    int t, k, count;
    char chess[8][8];

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    while(t--) {

        // * Initializing the count to 0
        count = 0;

        /*
        *   Accepting the value of k i.e. the number of
        *   distinct cells, king can travel for the current test case
        */
        cin>>k;

        // * Forming the chess board of size 8x8
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {

                /*
                *   For each cell, increment the count by one
                *   and place a 'X' in that cell
                */
                count++;
                chess[i][j] = 'X';

                /*
                *   If the number of cells, king has travelled
                *   or encountered till now are less than or
                *   equal to k, update the current cells value to '.'
                */
                if(count<=k) {
                    chess[i][j] = '.';
                }
            }
        }

        /*
        *   Place the king at the first element of the chess board.
        *   Updating the value of that index by 'O'
        */
        chess[0][0] = 'O';

        // * Printing the chess board
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                cout<<chess[i][j];
            }
            cout<<endl;
        }
    }
}