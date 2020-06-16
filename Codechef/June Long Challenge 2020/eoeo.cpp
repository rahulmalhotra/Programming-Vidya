/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef EOEO Problem (June Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JUNE20B/problems/EOEO
*/
#include <iostream>
#include <limits>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases;
    long long int ts, tsrem, numberOfValuesForJs;
    bool count;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the strength of tom for the current test case
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>ts;

        /*
        *   Initializing the number of valid values for jerry's
        *   strength to 0 and count boolean to false for current test case
        */
        numberOfValuesForJs = 0;
        count = false;

        /*
        *   If the strength of tom is odd, the valid values for jerry's
        *   strength will be all even numbers between 1 and ts which will be ts/2
        */
        if(ts&1) {
            cout<<ts/2<<endl;
            continue;
        }

        /*
        *   Dividing ts by 4 and storing the quotient in ts itself
        *   and remainder in tsrem variable
        */
        tsrem = ts % 4;
        ts = ts / 4;

        /*
        *   Looping while any one of ts or tsrem is not zero.
        *   Loop will break when both are zero
        */
        while(ts!=0 || tsrem!=0) {

            // * If tsrem is not 0
            if(tsrem!=0) {

                /*
                *   If we haven't started counting numbers with valid values
                *   for jerry's strength yet, start counting from now.
                *   Setting count = true.
                *   Otherwise, if we've already started counting,
                *   add the current value of ts in total number of valid values for js.
                *   Also, add 1 in it because, remainder is not zero
                */
                if(!count) {
                    count = true;
                } else {
                    numberOfValuesForJs += ts + 1;
                }
            }
            /*
            *   Otherwise, If remainder is zero and we've started counting previously,
            *   count the current value of ts in total number of valid values
            */
            else if(count) {
                numberOfValuesForJs += ts;
            }

            /*
            *   Dividing ts by 2 and updating the remainder (tsrem)
            *   Also, updating ts by storing the quotient in ts itself
            */
            tsrem = ts % 2;
            ts = ts / 2;
        }

        /*
        *   Displaying the total number of valid values for jerry's strength
        *   for the current test case
        */
        cout<<numberOfValuesForJs<<endl;
    }
}