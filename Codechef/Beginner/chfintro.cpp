/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CHFINTRO Problem
*   Problem Link:- https://www.codechef.com/problems/CHFINTRO
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfPersons, goodRating, currentRating;

    /*
    *   Accepting the total number of persons and
    *   minimum rating to qualify
    */
    cin>>numberOfPersons>>goodRating;

    /*
    *   Accepting the current rating for each person
    *   and displaying the result for that
    *   person based on the rating
    */
    while(numberOfPersons--) {
        cin>>currentRating;
        if(currentRating<goodRating) {
            cout<<"Bad boi"<<endl;
        } else {
            cout<<"Good boi"<<endl;
        }
    }
}