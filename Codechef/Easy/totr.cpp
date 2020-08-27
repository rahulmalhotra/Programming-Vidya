/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TOTR Problem
*   Problem Link:- https://www.codechef.com/problems/TOTR
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Initializing variables
    int numberOfTestCases;
    string m, s;
    char english[26] = {
        'a', 'b', 'c', 'd', 'e',
        'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };
    unordered_map<char, char> bytelandiantoenglish({{ '_', ' ' }});

    // * Accepting the number of test cases and permutation m
    cin>>numberOfTestCases>>m;

    // * Setting up map to convert byteland characters to english characters
    for(int i=0; i<m.size(); i++) {
        bytelandiantoenglish[english[i]] = m[i];
    }

    // * Executing each test case one by one
    while (numberOfTestCases--)
    {
        // * Accepting the sentence for the current test case
        cin>>s;

        // * Checking each character in the sentence one by one
        for(int i=0; i<s.size(); i++) {

            /*
            *   Getting the english translation of the current character
            *   of the sentence, in currentEnglishChar variable
            */
            char currentEnglishChar = bytelandiantoenglish[char(tolower(s[i]))];

            // * If we have a valid mapping for the current character in english
            if(currentEnglishChar) {

                /*
                *   If the current character is in uppercase,
                *   display the equivalent uppercase english character
                */
                if(isupper(s[i])) {
                    cout<<char(toupper(currentEnglishChar));
                }

                // * Otherwise, display the equivalent lowercase english character
                else {
                    cout<<currentEnglishChar;
                }
            }

            /*
            *   If we don't have a valid mapping in english,
            *   display the character as it is
            */
            else {
                cout<<s[i];
            }
        }

        // * Adding a new line before executing the next test case
        cout<<endl;
    }
}