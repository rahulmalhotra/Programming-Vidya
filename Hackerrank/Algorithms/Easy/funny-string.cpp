/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Funny String problem
*   Problem Link:- https://www.hackerrank.com/challenges/funny-string/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {

    // * Initializing variables
    int length = s.length(), diff[10000], i;

    /*
    *   Calculating the absolute differences between adjacent elements
    *   and forming the difference array
    */
    for(i=1; i<length; i++) {
        diff[i-1] = abs(s[i] - s[i-1]);
    }

    // * Checking if the difference array is palindrome or not
    for(i=0; i<length-1; i++) {
        if(diff[i] != diff[length-2-i]) {
            break;
        }
    }

    // * If the difference array is palindrome, return "Funny"
    if(i==length-1) {
        return "Funny";
    }

    // * Otherwise, return "Not Funny"
    return "Not Funny";
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
