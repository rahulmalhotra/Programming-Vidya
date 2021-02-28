/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Anagram problem
*   Problem Link:- https://www.hackerrank.com/challenges/anagram/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {

    // * Initializing variables
    int freqA[26] = {0}, freqB[26] = {0}, length = s.length(), count = 0;

    /*
    *   If the length of string is odd, return -1 as it cannot be broken into two
    *   substrings of equal length
    */
    if(length&1) {
        return -1;
    }

    // * Forming the two equal substrings from string s
    string s1 = s.substr(0, length/2);
    string s2 = s.substr(length/2, length/2);

    // * Calculating the frequency of each character in both the substrings
    for(int i=0; i<length/2; i++) {
        freqA[s1[i]-'a']++;
        freqB[s2[i]-'a']++;
    }

    /*
    *   Calculating and returning the minimum number of characters to change
    *   to make the two substrings anagrams of one another
    */
    for(int i=0; i<26; i++) {
        if(freqA[i]!=freqB[i]) {
            count+=abs(freqA[i]-freqB[i]);
        }
    }

    return count/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
