/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef NAME2 Problem
*   Problem Link:- https://www.codechef.com/problems/NAME2
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This function will return true if string 'a' is a subsequence of string 'b'
bool isSubsequence(string a, string b) {

    // * Initializing i and j index to 0
    int i=0, j=0;

    /*
    *   Checking each character of string b
    *   with each character of string a
    *   to confirm if a is a subsequence of b
    */
    while(b[j]!='\0') {
        if(a[i]==b[j]) {
            i++;
        }
        j++;
    }

    // * If the index i reaches to the end of string a, return true
    if(a[i]=='\0') {
        return true;
    }

    // * Otherwise, return false
    return false;
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

    // * Initializing variables
    int numberOfTestCases;
    bool allowedToMarry;
    string m, w;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the names of man and woman
        cin>>m>>w;

        // * Initializing allowedToMarry variable to false for the current test case
        allowedToMarry = false;

        // * Calculating the length of both names
        int mLength = m.size(), wLength = w.size();

        // * Checking if the shorter name is a substring of longer name
        if(mLength<wLength) {
            allowedToMarry = isSubsequence(m, w);
        } else {
            allowedToMarry = isSubsequence(w, m);
        }

        // * If man and woman are allowed to marry, print "YES"
        if(allowedToMarry) {
            cout<<"YES"<<endl;
        }

        // * Otherwise, print "NO"
        else {
            cout<<"NO"<<endl;
        }
    }
}