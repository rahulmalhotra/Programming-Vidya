/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Repeated String problem
*   Problem Link:- https://www.hackerrank.com/challenges/repeated-string/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    // * Initializing variables
    int length = s.length(), aCount = 0;
    long result = 0;

    // * Counting the number of 'a' in the string s
    for(int i=0; i<length; i++) {
        if(s[i]=='a') {
            aCount++;
        }
    }

    /*
    *   Calculating the number of 'a' when the string
    *   is repeated infinitely many times considering full
    *   repetitions within n characters
    */
    result = n/length * aCount;

    // * Calculating the remaining length of string
    int rem = n%length;

    /*
    *   Finding the number of 'a' in the remaining string
    *   and adding it to the result
    */
    for(int i=0; i<rem; i++) {
        if(s[i]=='a') {
            result++;
        }
    }

    // * Returning the final count of 'a'
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
