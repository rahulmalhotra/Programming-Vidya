/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Happy Ladybugs problem
*   Problem Link:- https://www.hackerrank.com/challenges/happy-ladybugs/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {

    // * Initializing variables
    unordered_map<char, int> colorMap;
    int happyCount = 0, unHappyCount = 0, spaceCount = 0, bLength = b.length();
    vector<int> unHappyIndexes;


    // * Creating a frequency map for all colors in the string
    for(int i=0; i<bLength; i++) {
        colorMap[b[i]]++;
    }

    /*
    *   If the first character is a space,
    *   increase the space count by 1. Otherwise,
    *   if the first ladybug is happy, increase the
    *   happy count by 1. Otherwise,
    *   increase the unhappy count by 1 and
    *   store it's index in unHappyIndexes vector
    */
    if(b[0]=='_') {
        spaceCount++;
    } else if(b[0]==b[1]) {
        happyCount++;
    } else {
        unHappyCount++;
        unHappyIndexes.push_back(0);
    }

    /*
    *   Checking for all the characters in the string
    *   one by one except the first and last character
    */
    for(int i=1; i<bLength-1; i++) {

        /*
        *   If the current character is a space,
        *   increase the space count by 1. Otherwise,
        *   if the current ladybug is happy, increase the
        *   happy count by 1. Otherwise,
        *   increase the unhappy count by 1 and
        *   store it's index in unHappyIndexes vector
        */
        if(b[i]=='_') {
            spaceCount++;
        } else if(b[i]==b[i-1] || b[i]==b[i+1]) {
            happyCount++;
        } else {
            unHappyCount++;
            unHappyIndexes.push_back(i);
        }
    }

    /*
    *   If the last character is a space,
    *   increase the space count by 1. Otherwise,
    *   if the last ladybug is happy, increase the
    *   happy count by 1. Otherwise,
    *   increase the unhappy count by 1 and
    *   store it's index in unHappyIndexes vector
    */
    if(b[bLength-1]=='_') {
        spaceCount++;
    } else if(b[bLength-1] == b[bLength-2]) {
        happyCount++;
    } else {
        unHappyCount++;
        unHappyIndexes.push_back(bLength-1);
   }

    /*
    *   If all the lady bugs are happy,
    *   return "YES"
    */
    if(happyCount==bLength-spaceCount) {
        return "YES";
    }

    /*
    *   If there are some unhappy ladybugs and
    *   there is no space, return "NO" as we cannot make
    *   those ladybugs happy
    */
    else if(spaceCount==0) {
        return "NO";
    }

    // * Otherwise
    else {

        /*
        *   If there is a ladybug which is uhappy
        *   and alone, return "NO" as we cannot make
        *   this ladybug happy
        */
        int unHappyIndexesLength = unHappyIndexes.size();
        for(int i=0; i<unHappyIndexesLength; i++) {
            if(colorMap[b[unHappyIndexes[i]]]==1) {
                return "NO";
            }
        }

        /*
        *   Otherwise, return "YES" as we can make
        *   all the unhappy ladybugs happy
        */
        return "YES";
    }
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}