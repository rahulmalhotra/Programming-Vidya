/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef SALARY Problem
*   Problem Link:- https://www.codechef.com/problems/SALARY
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

    // * Setting up the variables with initial values
    int numberOfTestCases, numberOfWorkers, salary[100], minimumSalary, minimumNumberOfOperations;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Setting minimum number of operations to 0 and
        *   minimum salary to maximum value in range
        *   for the current test case
        */
        minimumNumberOfOperations = 0;
        minimumSalary = 10001;

        // * Accepting the number of workers for the current test case
        cin>>numberOfWorkers;

        // * Accepting the salary of each worker and calculating the minimum salary
        for(int i=0; i<numberOfWorkers; i++) {
            cin>>salary[i];
            minimumSalary = min(minimumSalary, salary[i]);
        }

        /*
        *   Calculating the minimum number of operations required
        *   to equalize the salary of all workers
        */
        for(int i=0; i<numberOfWorkers; i++) {
            minimumNumberOfOperations += salary[i] - minimumSalary;
        }

        // * Displaying the minimum number of operations
        cout<<minimumNumberOfOperations<<endl;
    }
}