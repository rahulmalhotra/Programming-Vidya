/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TSHIRTS Problem
*   Problem Link:- https://www.codechef.com/problems/TSHIRTS
*	Website:- www.programmingvidya.com
*/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

// * Initializing global variables
vector<vector<int> > tshirtToPersonsVector;
int ALL_PERSONS;
long long store[1025][101];

long long possibleArrangements(int mask, int tshirtId) {

    /*
    *   If we've provided distinct t-shirts to all the persons,
    *   return 1 as this is one possible arrangement
    */
    if(mask==ALL_PERSONS) {
        return 1;
    }

    /*
    *   If we don't have any more tshirts left and persons are still waiting
    *   for their tshirt, return 0 as this is not a valid possible arrangement
    */
    if(tshirtId==101) {
        return 0;
    }

    /*
    *   If we've already calculated the result for this sub-problem
    *   considering the current mask and tshirt id, return that result
    */
    if(store[mask][tshirtId]!=-1) {
        return store[mask][tshirtId];
    }

    // * Initializing answer to 0
    long long answer = 0;

    /*
    *   Calculating the possible arrangements
    *   if we skip the current t-shirt and adding
    *   it to the answer
    */
    answer = possibleArrangements(mask, tshirtId+1);

    /*
    *   Providing the current t-shirt to all the eligible persons
    *   one by one and adding the possible arrangements to the answer
    */
    vector<int> personVector = tshirtToPersonsVector[tshirtId];
    int personVectorLength = personVector.size();
    for(int i=0; i<personVectorLength; i++) {
        if((mask&(1<<personVector[i]))==0) {
            answer += possibleArrangements(mask|(1<<personVector[i]), tshirtId+1);
        }
    }

    // * Performing answer modulo 10^9 + 7
    answer %= 1000000007;

    // * Storing the answer for future use
    store[mask][tshirtId] = answer;

    // * Returning the answer
    return answer;
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
    int numberOfTestCases, numberOfPersons, tshirtId;
    string numberOfPersonsString, tshirtIdString;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Reserving memory for the t-shirt to person reverse mapping vector
    tshirtToPersonsVector.reserve(101);

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Accepting the number of persons
        *   for the current test case
        */
        cin>>numberOfPersons;

        // * Accepting new line character
        getchar();

        /*
        *   Calculating all persons mask
        *   for the given number of persons
        *   in the current test case
        */
        ALL_PERSONS = (1<<numberOfPersons) - 1;

        // * Initializing store array values with -1
        memset(store, -1, sizeof(store));

        /*
        *   Clearing the t-shirt to persons vector
        *   for the current test case
        */
        for(int i=1; i<101; i++) {
            tshirtToPersonsVector[i].clear();
        }

        /*
        *   Accepting the input and forming tshirt to persons
        *   vector for the current test case
        */
        for(int i=0; i<numberOfPersons; i++) {
            getline(cin, numberOfPersonsString);
            stringstream ss1(numberOfPersonsString);
            while(ss1>>tshirtIdString) {
                stringstream ss2(tshirtIdString);
                ss2>>tshirtId;
                tshirtToPersonsVector[tshirtId].push_back(i);
            }
        }

        /*
        *   Displaying the total number of possible arrangements
        *   such that each person is wearing a different tshirt
        */
        cout<<possibleArrangements(0, 1)<<endl;
    }

	return 0;
}