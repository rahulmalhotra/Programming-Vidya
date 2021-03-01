/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Two Strings problem
*   Problem Link:- https://www.hackerrank.com/challenges/two-strings/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    // * Initializing variables
    int freqA[26] = {0}, freqB[26] = {0}, length1 = s1.length(), length2 = s2.length();

    // * Forming the frequency array for characters of string 1
    for(int i=0; i<length1; i++) {
        freqA[s1[i]-'a']++;
    }

    // * Forming the frequency array for characters of string 2
    for(int i=0; i<length2; i++) {
        freqB[s2[i]-'a']++;
    }

    /*
    *   If any of the character is present in both string 1 and string 2,
    *   return "YES"
    */
    for(int i=0; i<26; i++) {
        if(freqA[i] && freqB[i]) {
            return "YES";
        }
    }

    // * Otherwise, return "NO"
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
