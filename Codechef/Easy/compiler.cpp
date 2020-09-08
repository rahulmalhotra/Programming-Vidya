/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef COMPILER Problem
*   Problem Link:- https://www.codechef.com/problems/COMPILER
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

// * This function will return the length of longest prefix for a given string
int lengthOfLongestPrefix(string s) {

    // * Initializing the variables
    stack<int> st;
    int size = s.size(), longestPrefixLength = 0;

    // * Iterating the string
    for(int i=0; i<size; i++) {

        // * If the current character is an opening bracket, push it onto the stack
        if(s[i]=='<') {
            st.push(s[i]);
        }

        // * Otherwise, if the current character is a closing bracket
        else if(s[i]=='>') {

            /*
            *   If the stack is empty, break the loop as we've already found
            *   the longest possible prefix.
            */
            if(st.empty()) {
                break;
            }

            /*
            *   Otherwise, pop the stack. If the stack is now empty,
            *   update the length of longest prefix with the
            *   number of elements spanned till now
            */
            else {
                st.pop();
                if(st.empty())
                    longestPrefixLength = i+1;
            }
        }
    }

    // * Return the length of longest prefix
    return longestPrefixLength;
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
    int numberOfTestCases;
    string s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    /*
    *   Executing each test case one by one.
    *   Accepting the string and displaying the length of longest prefix
    *   for the accepted string
    */
    while(numberOfTestCases--) {
        cin>>s;
        cout<<lengthOfLongestPrefix(s)<<endl;
    }
}