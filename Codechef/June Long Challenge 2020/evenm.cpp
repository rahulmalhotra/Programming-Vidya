/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef EVENM Problem (June Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JUNE20B/problems/EVENM
*/
#include <iostream>
#include <limits>
using namespace std;

int main() {

    // * Initializing variables
    int numberOfTestCases, n, k;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Clearing the buffer memory before taking input and accepting n
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>n;

        /*
        *   Initializing variable k to 1 for the current test case.
        *   This variable will be used to display matrix and will have a
        *   range from 1 to n*n
        */
        k=1;

        // * Looping rows and columns from 0 to n-1 to form the matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                /*
                *   If n is even, for every odd row index,
                *   we'll display reverted/swapped integers in pair of 2
                *   and increment k and j by 2 as we displayed 2 integers together
                *   Otherwise, we'll simply display value of k and increment it by 1
                */
                if(!(n&1) && (i&1)) {
                    cout<<k<<" "<<k++<<" ";
                    k++;
                    j++;
                } else {
                    cout<<k++<<" ";
                }
            }

            // * Adding endl before printing next row of matrix
            cout<<endl;
        }
    }
}