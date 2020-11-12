/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank HackerRank in a String! problem
*   Problem Link:- https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {

    // * Initializing variables
    int length = s.length(), j=0;
    string hk = "hackerrank";

    /*
    *   Checking each character of
    *   the string one by one
    */
    for(int i=0; i<length && j<10; i++) {

        /*
        *   If the current character is present
        *   in the string hackerrank, increase the
        *   index of hackerrank string by 1
        */
        if(hk[j]==s[i]) {
            j++;
        }
    }

    /*
    *   If the hackerrank string is fully processed,
    *   print "YES"
    */
    if(j==10) {
        return "YES";
    }

    // * Otherwise, print "NO"
    return "NO";
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

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}