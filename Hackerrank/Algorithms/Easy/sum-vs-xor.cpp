/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Sum vs XOR problem
*   Problem Link:- https://www.hackerrank.com/challenges/sum-vs-xor/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the sumXor function below.
long sumXor(long n) {

    // * Initializing variables
    int count = 0;

    // * Looping while the number n is not zero
    while(n) {

        /*
        *   If the last bit of the number is 0,
        *   increment the count by 1
        */
        if(!(n&1)) {
            count++;
        }

        // * Right shift the number by 1 bit
        n = n>>1;
    }

    // * Returning 2^(number of zeroes in binary form of n)
    return 1L << count;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
