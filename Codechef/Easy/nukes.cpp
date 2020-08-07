/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef NUKES Problem
*   Problem Link:- https://www.codechef.com/problems/NUKES
*/
#include <iostream>
#include <stdio.h>
using namespace std;

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
    int totalNumberOfParticles, maximumNumberOfParticlesInAChamber, totalNumberOfChambers;

    // * Accepting the input values
    cin>>totalNumberOfParticles>>maximumNumberOfParticlesInAChamber>>totalNumberOfChambers;

    // * Calculating and displaying the number of particles in each chamber
    for(int i=0; i<totalNumberOfChambers; i++) {
        cout<<totalNumberOfParticles%(maximumNumberOfParticlesInAChamber+1)<<" ";
        totalNumberOfParticles/=(maximumNumberOfParticlesInAChamber+1);
    }

	return 0;
}