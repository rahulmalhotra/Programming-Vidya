/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CLEANUP Problem
*   Problem Link:- https://www.codechef.com/problems/CLEANUP
*/
#include <iostream>
#include <bitset>
#include <stdio.h>
using namespace std;
template <size_t bitsetsize>

/*
*   This method is used to display alternate unset indices of a bitset
*   depending on the value of toggle. If toggle is false, it'll start with
*   the first unset bit and display indices of alternate bits that are not set. If
*   toggle is true, it'll start with the second unset bit and display indices of
*   alternate bits that are not set.
*/
void displayAlternateJobIndices(bitset<bitsetsize> &b, int n, bool toggle) {

    /*
    *   If toggle is false and the bit is not set,
    *   display the index and set toggle to true
    *   Else if toggle is true and the bit is not set,
    *   we have to skip this index, as we're considering alternate indices.
    *   Set toggle to false so that we can consider the next index
    */
    for(int i=1; i<=n; i++) {
        if(!b.test(i) && !toggle) {
            cout<<i<<" ";
            toggle = true;
        } else if(!b.test(i) && toggle) {
            toggle = false;
        }
    }
}

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
    int t, n, m, index;
    bool toggle;
    bitset<1001> b;

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    while(t--) {

        /*
        *   Accepting the total number of jobs and the number of jobs
        *   that are completed for the current test case
        */
        cin>>n>>m;

        /*
        *   Accepting the indices of the jobs that are completed and
        *   flipping the bits for those jobs in the bitset
        */
        for(int i=1; i<=m; i++) {
            cin>>index;
            b.flip(index);
        }

        // * Displaying the list of indices of the job assigned to Chef
        displayAlternateJobIndices(b, n, false);

        // * Displaying a new line
        cout<<endl;

        // * Displaying the list of indices of the job assigned to Chef's assistant
        displayAlternateJobIndices(b, n, true);

        // * Resetting the bitset for next test case
        b.reset();

        // * Displaying a new line before considering the next test case
        cout<<endl;
    }

	return 0;
}