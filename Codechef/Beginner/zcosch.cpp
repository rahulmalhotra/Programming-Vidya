/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef ZCOSCH Problem
*   Problem Link:- https://www.codechef.com/problems/ZCOSCH
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing the rank variable
    int rank;

    // * Accepting the rank from user
    cin>>rank;

    /*
    *   Displaying the scholarship
    *   according to the below conditions:-
    *   100% Scholarship if 1<=rank<=50
    *   50% Scholarship if 50<rank<=100
    *   0% Scholarship otherwise
    */
    if(rank>=1 && rank<=50) {
        cout<<"100";
    } else if(rank>50 && rank<=100) {
        cout<<"50";
    } else {
        cout<<"0";
    }
}