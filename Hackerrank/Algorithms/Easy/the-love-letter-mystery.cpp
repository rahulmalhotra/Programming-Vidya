/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank The Love-Letter Mystery problem
*   Problem Link:- https://www.hackerrank.com/challenges/the-love-letter-mystery/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {

    // * Initializing variables
    int length = s.length(), numberOfOperations = 0;

    /*
    *   Checking each character of the string uptil half length with it's
    *   corresponding character and storing the number of operations
    *   required to make both characters equal
    *   in the numberOfOperations variable
    */
    for(int i=0; i<length/2; i++) {
        numberOfOperations += max(s[length-i-1], s[i]) - min(s[length-i-1], s[i]);
    }

    // * Returning the number of operations
    return numberOfOperations;
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

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
