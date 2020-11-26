/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Palindrome Index problem
*   Problem Link:- https://www.hackerrank.com/challenges/palindrome-index/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {

    // * Initializing variables
    int length = s.length(), numberOfDeletions = 0, storedIndex = -1;
    int i = 0, j = length-1;

    // * If the string length is 1, it is a palindrome. Return -1
    if(length == 1) {
        return -1;
    }

    // * If the string length is 2
    if(length == 2) {

        /*
        *   If both the characters in the string are equal,
        *   it is a palindrome. Return -1
        */
        if(s[0]==s[1]) {
            return -1;
        }

        // * Otherwise, return 0
        else {
            return 0;
        }
    }

    // * Loop until i<=j
    while(i<=j) {

        // * If the characters at index i and j are not equal
        if(s[i]!=s[j]) {

            /*
            *   Increase the number of deletions by 1 as we're going
            *   to perform a deletion here
            */
            numberOfDeletions++;

            /*
            *   If we've already deleted 1 element in the past, return -1
            *   as the string is not a palindrome
            */
            if(numberOfDeletions>1) {
                return -1;
            }

            /*
            *   If the character at index i can be deleted, store i
            *   and increment i by 1
            */
            if(s[i+1]==s[j] && s[i+2]==s[j-1]) {
                storedIndex = i;
                i++;
            }

            /*
            *   If the character at index j can be deleted, store j
            *   and decrement j by 1
            */
            else if(s[j-1]==s[i] && s[j-2]==s[i+1]) {
                storedIndex = j;
                j--;
            }

            // * Otherwise return -1
            else {
                return -1;
            }
        }

        /*
        *   Otherwise, if the characters at index i and j are equal,
        *   increment i by 1 and decrement j by 1
        */
        else {
            i++;
            j--;
        }
    }

    // * Return the stored index
    return storedIndex;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
