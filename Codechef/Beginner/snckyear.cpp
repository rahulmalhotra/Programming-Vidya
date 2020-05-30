/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef SNCKYEAR Problem
*   Problem Link:- https://www.codechef.com/problems/SNCKYEAR
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting integer n
        cin>>n;

        /*
        *   Answer is HOSTED if n is 2010,
        *   2015, 2016, 2017 or 2019. Otherwise,
        *   the answer is NOT HOSTED
        */
        switch(n) {
            case 2010:
            case 2015:
            case 2016:
            case 2017:
            case 2019:
                cout<<"HOSTED"<<endl;
                break;
            default:
                cout<<"NOT HOSTED"<<endl;
                break;
        }
    }
}