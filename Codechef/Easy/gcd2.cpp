/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef GCD2 Problem
*   Problem Link:- https://www.codechef.com/problems/GCD2
*   Website:- www.programmingvidya.com
*   Note:- Please make sure to remove the comments before submitting the solution to Codechef,
*          as the source limit is 2000 bytes
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This method is used to return the GCD of two integers
int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

/*
*   This method is used to find the initial remainder
*   when a very large number stored in string 's'
*   is divided by an integer 'a'. The result will always be
*   less than or equal to 'a'
*/
int getInitialRemainder(int a, string s) {
    int length = s.size(), rem = 0;
    for(int i=0; i<length; i++) {
        rem = ( (s[i] - '0') + rem * 10 ) % a;
    }
    return rem;
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
    int numberOfLines, a, b;
    string s;

    // * Accepting the number of lines to follow
    cin>>numberOfLines;

    // * Accepting input for each line and calculating the gcd
    while(numberOfLines--) {

        // * Accepting the integer 'a' and string 's'
        cin>>a>>s;

        // * If integer 'a' is 0, display the string 's' as the gcd of 'a' and 's'
        if(a==0) {
            cout<<s<<endl;
        }

        // * If integer 'a' is not 0
        else {

            // * Calculate the initial remainder when 's' is divided by 'a'
            b = getInitialRemainder(a, s);

            /*
            *   Pass the remainder 'b' and
            *   the integer 'a' in gcd function
            *   to calculate the gcd and display that
            */
            cout<<gcd(a, b)<<endl;
        }
    }
}