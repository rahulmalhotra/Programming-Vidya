/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef CARVANS Problem
*   Problem Link:- https://www.codechef.com/problems/CARVANS
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    // * Initializing fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Initializing the variables
	int numberOfTestCases, numberOfCars, numberOfCarsAtMaximumSpeed, carSpeed, maxSpeed;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Considering each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Initializing number of cars at maximum speed to 1
        *   as the first car which entered the straight segment
        *   will surely run at maximum speed
        */
        numberOfCarsAtMaximumSpeed = 1;

        // * Accepting the number of cars for the current test case
        cin>>numberOfCars;

        // * Accepting the speed of first car and setting it as maximum speed
        cin>>maxSpeed;

        // * Considering other cars one by one
        while(--numberOfCars) {

            // * Accepting the speed of current car
            cin>>carSpeed;

            /*
            *   If the speed of current car is less than
            *   or equal to maximum speed encountered till now,
            *   increment the number of cars at maximum speed by 1,
            *   as the current car can continue with it's speed.
            *   Also, set the value of maximum speed as the speed of current car,
            *   as any upcoming car cannot have speed more than this maximum speed
            */
            if(carSpeed <= maxSpeed) {
                numberOfCarsAtMaximumSpeed++;
                maxSpeed = carSpeed;
            }
        }

        // * Display the number of cars at maximum speed for the current test case
        cout<<numberOfCarsAtMaximumSpeed<<endl;
    }

	return 0;
}