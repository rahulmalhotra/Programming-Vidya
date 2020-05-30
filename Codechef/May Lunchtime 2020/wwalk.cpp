/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef WWALK Problem (May 2020 Lunch Time)
*   Problem Link:- https://www.codechef.com/LTIME84B/problems/WWALK
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, numberOfSeconds, speedOfAlice[100005], speedOfBob;
    long totalDistanceOfAlice, totalDistanceOfBob, wierdDistance;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Initializing wierd distance, total distance of alice
        *   and total distance of bob to 0 for the current test case
        */
        wierdDistance = 0;
        totalDistanceOfAlice = 0;
        totalDistanceOfBob = 0;

        // * Accepting the number of seconds for current test case
        cin>>numberOfSeconds;

        // * Accepting speed of Alice after each second
        for(int i=0; i<numberOfSeconds; i++) {
            cin>>speedOfAlice[i];
        }

        // * Accepting speed of Bob after each second
        for(int i=0; i<numberOfSeconds; i++) {
            cin>>speedOfBob;

            /*
            *   If the speed of alice is equal to the speed of bob for current second
            *   and the total distance travelled by Alice is also equal to the total
            *   distance travelled by Bob till now, add the current distance to wierd distance
            */
            if(
                speedOfBob==speedOfAlice[i] &&
                totalDistanceOfAlice==totalDistanceOfBob
            ) {
                wierdDistance += speedOfBob;
            }

            /*
            *   Updating the total distance travelled by Alice
            *   and total distance travelled by Bob
            */
            totalDistanceOfAlice += speedOfAlice[i];
            totalDistanceOfBob += speedOfBob;
        }

        // * Displaying the wierd distance for the current test case
        cout<<wierdDistance<<endl;
    }
}