/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Making Anagrams problem
*   Problem Link:- https://www.hackerrank.com/challenges/making-anagrams/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {

    // * Initializing variables
    int s1Length = s1.length(), s2Length = s2.length();
    int freq1[26] = {0}, freq2[26]= {0}, minimumDeletions = 0;

    /*
    *   Storing the frequency of each letter in the first string
    *   in the frequency array freq1
    */
    for(int i=0; i<s1Length; i++) {
        freq1[s1[i] - 'a']++;
    }

    /*
    *   Storing the frequency of each letter in the second string
    *   in the frequency array freq2
    */
    for(int i=0; i<s2Length; i++) {
        freq2[s2[i] - 'a']++;
    }

    /*
    *   Calculating the minimum number of deletions required to make
    *   both strings anagrams
    */
    for(int i=0; i<26; i++) {
        minimumDeletions += abs(freq1[i] - freq2[i]);
    }

    // * Returning the minimum number of deletions
    return minimumDeletions;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
