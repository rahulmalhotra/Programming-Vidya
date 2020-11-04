/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Super Reduced String problem
*   Problem Link:- https://www.hackerrank.com/challenges/reduced-string/problem
*	Website:- www.programmingvidya.com
*/
#include <bits/stdc++.h>
using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {

    // * Initializing variables
    string result = "";
    int length = s.length();
    stack<char> st;

    // * Checking each character of the string one by one
    for(int i=0; i<length; i++) {

        // * If the stack is not empty
        if(!st.empty()) {

            /*
            *   If the topmost element of the stack is equal
            *   to the current character of the string, pop the stack
            *   and continue to the next character of the string
            */
            if(s[i] == st.top()) {
                st.pop();
                continue;
            }
        }

        // * Push the current character of the string into the stack
        st.push(s[i]);
    }

    // * While the stack is not empty
    while(!st.empty()) {

        /*
        *   Pop all the elements of the stack and
        *   form the result string
        */
        result.push_back(st.top());
        st.pop();
    }

    // * Reverse the result string
    reverse(result.begin(), result.end());

    // * Return the result string
    return result == "" ? "Empty String" : result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}