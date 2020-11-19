/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Beautiful Binary String problem
*   Problem Link:- https://www.hackerrank.com/challenges/beautiful-binary-string/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {

    // * Initializing variables
    int length = b.length(), count = 0;

    // * Iterating through the characters of the string
    for(int i=0; i<length-2; i++) {

        /*
        *   Counting the substrings "010" in the string.
        *   Each time a substring is found, the index 'i' is increased
        *   additionally by 2 so that two adjacent "010" substrings
        *   are counted only once
        */
        if(b.substr(i, 3).compare("010")==0) {
            count++;
            i+=2;
        }
    }

    // * Returning the count
    return count;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
