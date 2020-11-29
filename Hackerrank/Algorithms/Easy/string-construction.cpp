/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank String Construction problem
*   Problem Link:- https://www.hackerrank.com/challenges/string-construction/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {

    // * Initializing variables
    int length = s.length();
    unordered_set<char> charSet;

    /*
    *   Creating the charSet by storing each alphabet
    *   of the string in the set
    */
    for(int i=0; i<length; i++) {
        charSet.insert(s[i]);
    }

    /*
    *   Returning number of unique alphabets
    *   in the string which is the size of
    *   the charSet as it is the minimum
    *   cost of constructing a new string
    */
    return charSet.size();
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
