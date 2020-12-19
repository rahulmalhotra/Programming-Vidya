/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Two Characters problem
*   Problem Link:- https://www.hackerrank.com/challenges/two-characters/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {

    // * Initializing a pivot string with all english lowercase characters
    string pivot = "abcdefghijklmnopqrstuvwxyz";

    // * Initializing length and maxLength variables
    int length = s.length(), maxLength = 0;

    // * If the input string length is less than 2, return 0
    if(length<2) {
        return 0;
    }

    /*
    *   Considering all possible combinations
    *   of english lowercase characters one by one
    */
    for(int i=0; i<26; i++) {
        for(int j=i+1; j<26; j++) {

            // * Initializing variables
            char a = pivot[i], b = pivot[j];
            string result = "";
            int resultLength = 0, k;

            /*
            *   Checking the input string for current characters a and b,
            *   removing all other characters to form an alternating
            *   character string
            */
            for(k=0; k<length; k++) {
                if(s[k]==a || s[k]==b) {

                    /*
                    *   If we have a repeating character, break the loop
                    *   as the result string is invalid
                    */
                    if(s[k]==result[resultLength-1]) {
                        break;
                    }

                    // * Otherwise, add the current character to the result string
                    result += s[k];

                    // * Increment resultLength by 1
                    resultLength++;
                }
            }

            /*
            *   If the result string is valid i.e we've covered the
            *   whole length of input string, store the result string length
            *   in maxLength if it's greater than the current value of maxLength
            */
            if(k==length) {
                maxLength = max(maxLength, resultLength);
            }
        }
    }

    // * Returning the maxLength
    return maxLength;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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