/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef XYSTR Problem (June Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JUNE20B/problems/XYSTR
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, maximumPairs, i;
    char students[100001];

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting students for the current test case
        cin>>students;

        // * Initializing counter i and maximum pairs to 0 for current test case
        i=0;
        maximumPairs=0;

        // * Looping each character of string one by one
        while(students[i] != '\0') {

            /*
            *   If current character is equal to x and next character is y,
            *   we found a pair, increment maximum pairs by 1.
            *   Increment counter by 2 in order to skip this pair which is counted.
            *   Otherwise, if current character is y and next character is x,
            *   we found a pair, increment maximum pairs by 1.
            *   Increment counter by 2 in order to skip this pair which we counted.
            *   Otherwise, increment counter by 1.
            */
            if(students[i] == 'x' && students[i+1] == 'y') {
                maximumPairs++;
                i+=2;
            } else if(students[i] == 'y' && students[i+1] == 'x') {
                maximumPairs++;
                i+=2;
            } else {
                i++;
            }
        }

        // * Display maximum pairs for the current test case
        cout<<maximumPairs<<endl;
    }
}