/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef DIFFSUM Problem
*   Problem Link:- https://www.codechef.com/problems/DIFFSUM
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int n1, n2;

    // * Accepting two numbers
    cin>>n1>>n2;

    /*
    *   Displaying the difference if first number (n1) is
    *   greater than second number (n2)
    *   Otherwise, displaying their sum
    */
    if(n1>n2) {
        cout<<n1-n2;
    } else {
        cout<<n1+n2;
    }
}