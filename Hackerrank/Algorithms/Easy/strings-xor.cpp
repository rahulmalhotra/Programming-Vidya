/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank XOR Strings problem
*   Problem Link:- https://www.hackerrank.com/challenges/strings-xor/problem
*   Website:- www.programmingvidya.com
*   Code Updates:-
*   Updated = to == on line number 23
*   Updated = to += on line number 24 and 26
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string strings_xor(string s, string t) {

    string res = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == t[i])
            res += '0';
        else
            res += '1';
    }

    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << strings_xor(s, t) << endl;
    return 0;
}