/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MARCHA1 Problem
*   Problem Link:- https://www.codechef.com/problems/MARCHA1
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
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
	int numberOfTestCases, numberOfBankNotes, amountAskedByMuggers, bankNotesInWallet[20], sum, totalPermutations;
    bool sumFound;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing sum found to false for the current test case
        sumFound = false;

        // * Accepting the number of bank notes and the amount asked by muggers
        cin>>numberOfBankNotes>>amountAskedByMuggers;

        // * Accepting the value of each bank note one by one
        for(int i=0; i<numberOfBankNotes; i++) {
            cin>>bankNotesInWallet[i];
        }

        // * Calculating the total permutations for number of bank notes
        totalPermutations = pow(2, numberOfBankNotes);

        // * Considering each permutation one by one
        for(int j=1; j<=totalPermutations; j++) {

            // * Initializing sum to 0
            sum=0;

            // * Checking each bit from zero to number of bank notes in current permutation
            for(int k=0; k<numberOfBankNotes; k++) {

                /*
                *   If kth bit of current permutation is set, add the
                *   corresponding bank note value to sum
                */
                if((j>>(k)) & 1) {
                    sum+=bankNotesInWallet[k];
                }
            }

            // * If sum is equal to amountAskedByMuggers, set sumFound variable to true
            if(sum==amountAskedByMuggers) {
                sumFound = true;
            }
        }

        // * Print "Yes" for the current test case if sum found, otherwise print "No"
        if(sumFound) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

	return 0;
}