/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Game of Thrones - I problem
*   Problem Link:- https://www.hackerrank.com/challenges/game-of-thrones/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {

    // * Initializing variables
    int length = s.length(), freq[26] = {0}, numberOfAlphabetsWithOddFrequency = 0;

    /*
    *   Creating a frequency array consisting of the frequency
    *   of each alphabet in the string
    */
    for(int i=0; i<length; i++) {
        freq[s[i] - 'a']++;
    }

    // * Counting the number of alphabets in the string with odd frequencies
    for(int i=0; i<26; i++) {
        if(freq[i]&1) {
            numberOfAlphabetsWithOddFrequency++;
        }
    }

    /*
    *   If there is more than one alphabet with odd frequency in the string
    *   that means the string cannot be rearranged into a palindrome, return "NO"
    */
    if(numberOfAlphabetsWithOddFrequency>1) {
        return "NO";
    }

    // * Otherwise, return "YES" as the string can be rearranged into a palindrome
    else {
        return "YES";
    }
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
