/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Pangrams problem
*   Problem Link:- https://www.hackerrank.com/challenges/pangrams/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {

    // * Initializing variables
    int length = s.length();
    set<int> alphaset;

    // * Creating a set of characters encountered in the string
    for(int i=0; i<length; i++) {
        alphaset.insert(tolower(s[i]));
    }

    // * Removing the space from the set so that we only have alphabets left
    alphaset.erase(' ');

    /*
    *   If we have all the alphabets in the set,
    *   i.e. the size of set is 26,
    *   return "pangram" as the string is a pangram
    */
    if(alphaset.size()==26) {
        return "pangram";
    }

    // * Otherwise, return "not pangram"
    return "not pangram";
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}