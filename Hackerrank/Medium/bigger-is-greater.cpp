/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Bigger is Greater problem
*   Problem Link:- https://www.hackerrank.com/challenges/bigger-is-greater/problem
*   Note:- Use only the methods while submitting on the HackerRank platform
*          and not the main function
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*
*   This method is used to find the next greater character in the
*   string based on starting index and ending index as compared to
*   the character present in start - 1 index. Binary Search is being used
*/
int findGreaterChar(string& s, int start, int end) {

    // * Initializing variables
    int mid, key = start-1;

    /*
    *   Finding the character which is less than the character
    *   present at index 'key', if such character is found, we'll return the
    *   character to the left of it because
    *   character found < character at key < character returned
    */
    while(start<=end) {

        // * Calculating the mid
        mid = (start+end)/2;

        /*
        *   If character at mid is less than or equal to
        *   the character at key, find in the string to the left of mid
        */
        if(s[mid] <= s[key]) {
            end = mid - 1;
        }

        // * Otherwise, find in the string to the right of mid
        else {

            start = mid + 1;

            /*
            *   Returning character to the left of mid if character at start
            *   is less than the character at key
            */
            if(s[start]<s[key]) {
                return start - 1;
            }
        }
    }

    /*
    *   If all the characters in the string are greater than
    *   the character at index 'key', we can simply return the last character index
    *   as the string is sorted in descending order from start to end
    */
    return end;
}

/*
*   This method is used to find the next permutation of string s.
*   If no permutation is possible, it'll return false
*/
bool nextPermutation(string& s) {

    int length = s.size(), i;

    /*
    *   Iterating the string in a reverse order to check
    *   to check the first character which is smaller than the
    *   next character. The index of that first character will be stored in 'i'
    */
    for(i=length-2; i>=0; i--) {
        if(s[i]<s[i+1]) {
            break;
        }
    }

    /*
    *   If the string is already sorted in decreasing order,
    *   there is no possibility of lexicographically greater string
    *   than the current string
    */
    if(i<0) {
        return false;
    }

    /*
    *   Otherwise, find the character in the string to the right of
    *   character at the current index 'i' which is just greater than
    *   the current character in lexicographic order.
    *
    *   Swap the current character with that bigger character and
    *   reverse the string to the right of index i as it's already sorted
    *   in descending order. This will give us the
    *   next lexicographically greater string
    */
    else {
        int greaterCharIndex = findGreaterChar(s, i+1, length-1);
        swap(s[greaterCharIndex], s[i]);
        reverse(s.begin() + (i+1), s.end());
        return true;
    }
}

string biggerIsGreater(string s) {

    /*
    *   If we're not able to find the valid next permutation
    *   for the given string, return "no answer"
    */

    /*
    *   Uncomment this to use the standard functon given in C++ STL
    *   and comment the below function call to function implemented above
    if(next_permutation(s.begin(), s.end()) == 0) {
        return "no answer";
    }
    */

    // * Using the functon we implemented above
    if(!nextPermutation(s)) {
        return "no answer";
    }

    // * Returning the next permutation of string s
    return s;
}

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    // * Initializing variables
    int numberOfTestCases;
    string s;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the input string
        cin>>s;

        // * Displaying the lexicographically greater string
        cout<<biggerIsGreater(s)<<endl;
    }
}