/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Modified Kaprekar Numbers problem
*   Problem Link:- https://www.hackerrank.com/challenges/kaprekar-numbers/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {

    // * Initializing variables
    bool hasKaprekarNumber = false;

    // * Iterating the range
    for(int i=p; i<=q; i++) {

        // * Converting the current number into string
        string si = to_string((long) i*i);

        // * Finding the length of string
        int length = si.length();

        // * Dividing the string into left and right substrings
        string leftString = si.substr(0, length/2);
        string rightString = si.substr(length/2, length);

        // * Converting the left and right substrings back to integers
        int left = leftString.empty() ? 0 : stoi(leftString);
        int right = rightString.empty() ? 0 : stoi(rightString);

        /*
        *   If the sum of left and right integers is equal to i,
        *   i is a modified kaprekar number, display i
        */
        if(left + right == i) {
            cout<<i<<" ";
            hasKaprekarNumber = true;
        }
    }

    // * If no modified kaprekar number is found, display "INVALID RANGE"
    if(!hasKaprekarNumber) {
        cout<<"INVALID RANGE";
    }

}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
