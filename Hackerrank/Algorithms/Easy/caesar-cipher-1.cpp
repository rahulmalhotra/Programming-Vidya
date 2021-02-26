/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Caesar Cipher problem
*   Problem Link:- https://www.hackerrank.com/challenges/caesar-cipher-1/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    // * Initializing variables
    int length = s.length();
    string result = "";

    // * Checking all the characters of the string one by one
    for(int i=0; i<length; i++) {

        /*
        *   If the current character is not an alphabet,
        *   keep it as it is in the result string
        */
        if(!isalpha(s[i])) {
            result += s[i];
        }

        /*
        *   If the current character is a lowercase alphabet, rotate it by k
        *   and add it to the result string
        */
        else if(s[i]>=97) {
            result += 97+(s[i]-97+k)%26;
        }

        /*
        *   If the current character is an uppercase alphabet, rotate it by k
        *   and add it to the result string
        */
        else {
            result += 65+(s[i]-65+k)%26;
        }
    }

    // * Returning the result string
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
