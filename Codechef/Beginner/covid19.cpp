/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef COVID19 Problem
*   Problem Link:- https://www.codechef.com/problems/COVID19
*/
#include <iostream>
using namespace std;
int main() {

    // * Setting up the variables with initial values
    int numberOfTestCases, numberOfPatients, arr[8], count = 1, maxInfected = 1, minInfected = 9;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    while(numberOfTestCases--) {

        // * Accepting the number of patients for each test case
        cin>>numberOfPatients;

        // * Accepting the first patient location on number line
        cin>>arr[0];

        // * Accepting the locations of other patients on number line
        for(int i=1; i<numberOfPatients; i++) {

            cin>>arr[i];

            /*
            *   Checking if the distance between current patient and
            *   previous patient is greater than 2
            */
            if(arr[i] - arr[i-1] > 2) {

                /*
                *   Updating the maximum and minimum infected patients
                *   according to the count of previous set of patients
                */
                maxInfected = max(maxInfected, count);
                minInfected = min(minInfected, count);

                // * Resetting the count to analyse the next set of patients
                count = 1;

            } else {

                /*
                *   Incrementing the count if the distance between the
                *   current patient and previous patient <= 2
                */
                count++;
            }
        }

        /*
        *   Updating the maximum and minimum infected patients
        *   by analysing the last set of patients encountered
        *   for current test case
        */
        maxInfected = max(maxInfected, count);
        minInfected = min(minInfected, count);

        // * Displaying the output for current test case
        cout<<minInfected<<" "<<maxInfected<<endl;

        // * Resetting the variables for next test case
        count = 1;
        maxInfected = 1;
        minInfected = 9;
    }
}