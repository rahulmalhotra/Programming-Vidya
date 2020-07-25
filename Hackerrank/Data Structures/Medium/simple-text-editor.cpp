/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Simple Text Editor problem
*   Problem Link:- https://www.hackerrank.com/challenges/simple-text-editor/problem
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {

    // * Initializing variables
    stack<string> st;
    string newString, currentString = "";
    int numberOfQueries, type, k;

    // * Accepting the total number of queries
    cin>>numberOfQueries;

    // * Considering each query one by one
    while(numberOfQueries--) {

        // * Accepting the type of operation
        cin>>type;

        /*
        *   Append Operation
        *   1. Accepting the new string
        *   2. Pushing the copy of current string to the stack
        *   3. Updating the current string by appending the new string to it
        */
        if(type==1) {
            cin>>newString;
            st.push(currentString);
            currentString = currentString.append(newString);
        }

        /*
        *   Delete Operation
        *   1. Pushing the copy of current string to the stack
        *   2. Updating the current string by removing the last k characters
        */
        else if(type==2) {
            cin>>k;
            st.push(currentString);
            currentString.erase(currentString.size()-k);
        }

        /*
        *   Print Operation
        *   1. Displaying the kth character of current string present at index k-1
        */
        else if(type==3) {
            cin>>k;
            cout<<currentString[k-1]<<endl;
        }

        /*
        *   Undo Operation
        *   1. Updating the current string by the string at the top of the stack
        *   2. Popping the top-most string from the stack
        */
        else if(type==4) {
            currentString = st.top();
            st.pop();
        }
    }

    return 0;
}