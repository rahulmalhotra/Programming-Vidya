/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank CamelCase problem
*   Problem Link:- https://www.hackerrank.com/challenges/camelcase/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {

    /*
    *   Initializing variables.
    *   wordCount is initialized to 1
    *   for the first word
    */
    int length = s.length(), wordCount = 1;

    // * Checking each character of the string one by one
    for(int i=0; i<length; i++) {

        /*
        *   If the current character is uppercase,
        *   increment the wordCount by 1
        *   as it's the starting of a new word
        */
        if(isupper(s[i])) {
            wordCount++;
        }
    }

    // * Returning the wordCount
    return wordCount;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}