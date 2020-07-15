/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CRDGAME Problem (July Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JULY20B/problems/CRDGAME
*/
#include <iostream>
#include <limits>
#include <stdio.h>
using namespace std;

/*
*   This function calculates the sum of digits of a number and returns it.
*   It divides the number by 10, add the remainder to the sum
*   i.e. the number at the unit place. Finally, it updates the
*   original number to the value of quotient (which doesn't consist of digit at unit place)
*/
int sumOfDigits(int n) {
    int sum;
    for(sum=0; n!=0; n=n/10) {
        sum += n%10;
    }
    return sum;
}

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
    int t, n, a, b, chefScore, mortyScore, adigitSum, bdigitSum;

    // * Accepting the number of test cases
    cin>>t;

    // * Executing each test case one by one
    while(t--) {

        /*
        *   Initializing Chef's and Morty's score to 0
        *   for the current test case
        */
        chefScore = 0;
        mortyScore = 0;

        // * Accepting the number of rounds played
        cin>>n;

        // * Considering each round one by one
        while(n--) {

            /*
            *   Accepting the number on the card drawn by
            *   Chef and Morty for the current round
            */
            cin>>a>>b;

            // * Calculating the sum of digits for both the numbers
            adigitSum = sumOfDigits(a);
            bdigitSum = sumOfDigits(b);

            /*
            *   If the sum of digits of the number on the card
            *   drawn by chef is greater than the sum of digits
            *   of the number on the card drawn by morty, increment
            *   chef's score by one
            */
            if(adigitSum > bdigitSum) {
                chefScore++;
            }

            /*
            *   If the sum of digits of the number on the card
            *   drawn by morty is greater than the sum of digits
            *   of the number on the card drawn by chef, increment
            *   morty's score by one
            */
            else if(adigitSum < bdigitSum) {
                mortyScore++;
            }

            /*
            *   If the sum of digits of the number on the card
            *   drawn by chef is equal to the sum of digits
            *   of the number on the card drawn by morty, increment
            *   both chef's and morty's score by one
            */
            else {
                chefScore++;
                mortyScore++;
            }
        }

        /*
        *   If chef's score > morty's score
        *   display 0 followed by a <space> and chef's score
        */
        if(chefScore>mortyScore) {
            cout<<"0 "<<chefScore<<endl;
        }

        /*
        *   If morty's score > chef's score
        *   display 1 followed by a <space> and morty's score
        */
        else if(chefScore<mortyScore) {
            cout<<"1 "<<mortyScore<<endl;
        }

        /*
        *   If chef's score is equal to morty's score
        *   display 2 followed by a <space> and
        *   any of chef's score or morty's score as both are equal
        */
        else {
            cout<<"2 "<<chefScore<<endl;
        }
    }
}