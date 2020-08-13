/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef LEPERMUT Problem
*   Problem Link:- https://www.codechef.com/problems/LEPERMUT
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

    // * Declaring the variables
    int numberOfTestCases, n, prevElement, currentElement, numberOfInversions, numberOfLocalInversions;
    set<int> s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the size of permutation
        cin>>n;

        /*
        *   Initializing number of inversions
        *   and number of local inversions to 0
        *   for the current test case
        */
        numberOfInversions = 0;
        numberOfLocalInversions = 0;

        // * Accepting the first number and adding it to the set
        cin>>prevElement;
        s.insert(prevElement);

        /*
        *   Accepting other numbers and adding them to the set.
        *   Also, calculating the number of inversions and
        *   number of local inversions at the same time
        *   using previous element and current element.
        *   Marking the current element as the previous element at the end
        */
        for(int i=1; i<n; i++) {
            cin>>currentElement;
            s.insert(currentElement);
            numberOfInversions += distance(s.upper_bound(currentElement), s.end());
            numberOfLocalInversions += currentElement < prevElement ? 1 : 0;
            prevElement = currentElement;
        }

        /*
        *   If the number of inversions and number of local inversions
        *   are same, print "YES". Otherwise, print "NO"
        */
        if(numberOfInversions == numberOfLocalInversions) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

        // * Clear the set
        s.clear();
    }
}