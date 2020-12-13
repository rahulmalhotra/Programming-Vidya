/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Maximizing XOR problem
*   Problem Link:- https://www.hackerrank.com/challenges/maximizing-xor/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {

    /*
    *   Initializing variables and
    *   calculating the most significant bit
    *   which is integer value of log2(l xor r)
    */
    int msb = (int) log2(l^r), maxXor = 1;

    /*
    *   Calculating the maximum xor
    *   which is the number with all 1s
    *   in binary form uptil most significant bit
    */
    while(msb--) {
        maxXor = (maxXor<<1) + 1;
    }

    // * Returning the maximum xor
    return maxXor;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}
