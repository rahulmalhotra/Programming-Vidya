/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef POUR1 Problem
*   Problem Link:- https://www.codechef.com/problems/POUR1
*	Website:- www.programmingvidya.com
*/

#include <iostream>
#include <stdio.h>
using namespace std;

/*
*   This function is used to return the
*   gcd of two numbers a and b
*/
int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

/*
*   This method is used to count the steps required
*   to get the amount of water to measure
*   in one of the vessel
*/
int countSteps(int firstVesselCapacity, int secondVesselCapacity, int amountToMeasure) {

    // * Filling the first vessel to it's full capacity
    int firstVesselAmount = firstVesselCapacity;

    // * Keeping the second vessel empty
    int secondVesselAmount = 0;

    /*
    *   Initializing number of steps to 1
    *   as we've filled the first vessel
    */
    int steps = 1;

    /*
    *   Looping until we're not getting the amount to measure
    *   in one of the vessel
    */
    while(firstVesselAmount != amountToMeasure && secondVesselAmount != amountToMeasure) {

        /*
        *   Calculating the amount to transfer. The amount to transfer is
        *   the minimum of :- the amount of water second vessel can accomodate
        *   at the moment, the amount of water in first vessel
        */
        int amountToTransfer = min(firstVesselAmount, secondVesselCapacity - secondVesselAmount);

        /*
        *   Transferring the water from first to second vessel
        *   and incrementing the number of steps by 1
        */
        firstVesselAmount -= amountToTransfer;
        secondVesselAmount += amountToTransfer;
        steps++;

        /*
        *   If we've got the amount to measure
        *   in one of the vessels, break the loop
        */
        if(
            firstVesselAmount == amountToMeasure ||
            secondVesselAmount == amountToMeasure
        ) {
            break;
        }

        /*
        *   If the second vessel is full,
        *   empty the second vessel and
        *   increase the number of steps by 1
        */
        if(secondVesselAmount == secondVesselCapacity) {
            secondVesselAmount = 0;
            steps++;
        }

        /*
        *   If the first vessel is empty, make it full and
        *   increase the number of steps by 1
        */
        if(firstVesselAmount == 0) {
            firstVesselAmount = firstVesselCapacity;
            steps++;
        }
    }

    /*
    *   Returning the total steps taken
    *   to get the amount to measure
    *   in one of the vessel
    */
    return steps;
}

/*
*   This function is used to return the minimum steps that we need to perform
*   in order to get the amount of water to measure in one of the vessels
*/
int minSteps(int firstVesselCapacity, int secondVesselCapacity, int amountToMeasure) {

    /*
    *   If first vessel capacity is more than second vessel capacity,
    *   swap both as we're planning to have the greater amount vessel
    *   as the second vessel
    */
    if(firstVesselCapacity > secondVesselCapacity) {
        swap(firstVesselCapacity, secondVesselCapacity);
    }

    /*
    *   If the amount that bigger vessel can handle is less than
    *   the amount to measure, return -1
    */
    if(secondVesselCapacity < amountToMeasure) {
        return -1;
    }

    /*
    *   If this amount cannot be measured using the given vessels, return -1.
    *   We're checking the diophantine equation here
    */
    if((amountToMeasure % gcd(firstVesselCapacity, secondVesselCapacity)) != 0) {
        return -1;
    }

    /*
    *   Returning the minimum number of steps
    *   required to get the amount to measure in one of the vessel
    */
    return min(
        countSteps(firstVesselCapacity, secondVesselCapacity, amountToMeasure),
        countSteps(secondVesselCapacity, firstVesselCapacity, amountToMeasure)
    );
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
    int numberOfTestCases, firstVesselCapacity, secondVesselCapacity, amountToMeasure;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the first vessel capacity, second vessel capacity and
        *   the amount of water to measure for the current test case
        */
        cin>>firstVesselCapacity>>secondVesselCapacity>>amountToMeasure;

        /*
        *   Displaying the minimum steps required to get the
        *   amount to measure in one of the vessels for
        *   the current test case
        */
        cout<<minSteps(firstVesselCapacity, secondVesselCapacity, amountToMeasure)<<endl;
    }

	return 0;
}