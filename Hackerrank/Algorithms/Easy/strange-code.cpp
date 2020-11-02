/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Strange Counter problem
*   Problem Link:- https://www.hackerrank.com/challenges/strange-code/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {

    // * Initializing variables
    long remainder = 3;

    // * Performing calculations
    while(t>remainder) {
        t -= remainder;
        remainder *= 2;
    }

    // * Returning the result
    return remainder - t + 1;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}