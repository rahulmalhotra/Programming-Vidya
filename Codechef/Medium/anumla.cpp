/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ANUMLA Problem
*   Problem Link:- https://www.codechef.com/problems/ANUMLA
*	Website:- www.programmingvidya.com
*/

#include <iostream>
#include <stdio.h>
#include <set>
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
    int numberOfTestCases, n, n1, a, ans[15], sumArr[32770];
    multiset<int> s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the number of elements in the original array
        *   for the current test case
        */
        cin>>n;

        /*
        *   Calculating the number of elements in the
        *   subset sum array for the current test case
        */
        n1 = 1 << n;

        /*
        *   Accepting the elements of
        *   the subset sum array and inserting them
        *   in a multiset
        */
        for(int i=0; i<n1; i++) {
            cin>>a;
            s.insert(a);
        }

        /*
        *   Deleting the first element of the multi set
        *   as it's always zero
        */
        sumArr[0] = *s.begin();
        s.erase(s.begin());

        // * Initializing counters
        int j = 1, l = 0, k;

        // * While multiset is not empty
        while(!s.empty()) {

            // * Initializing k to the number of elements in sumArr
            k = j;

            /*
            *   Picking the front element of multiset,
            *   finding all the elements obtained by adding
            *   each element of sum array with the front element's value
            *   and updating the sum array. Also, deleting the first element
            *   found in the multi set which is equal to the result of current addition
            */
            a = *s.begin();
            for(int i=0; i<k; i++, j++) {
                sumArr[j] = a + sumArr[i];
                s.erase(s.find(sumArr[j]));
            }

            // * Storing the front element of multiset in ans array
            ans[l++] = a;
        }

        // * Displaying the ans array
        for(int i=0; i<l; i++) {
            cout<<ans[i]<<" ";
        }

        /*
        *   Adding a new line before executing
        *   the next test case
        */
        cout<<endl;
    }
	return 0;
}