/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef NUMFACT Problem
*   Problem Link:- https://www.codechef.com/problems/NUMFACT
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;

int prime[1000001];

/*
*   This function is used to setup minimum prime factor
*   for each number till 10^6
*/
void generateMinimumPrimeFactors() {

    // * Initially marking each number as the minimum prime factor of itself
    for(int i=1; i<1000001; i++) {
        prime[i] = i;
    }

    /*
    *   Checking for all the numbers,
    *   if the current number is the minimum prime factor of itself,
    *   update the minimum prime factors of the multiples
    *   of the current number with the current number.
    */
    for(int i=2; i*i<1000001; i++) {
        if(prime[i]==i) {
            for(int j=i*i; j<1000001; j+=i) {
                prime[j] = i;
            }
        }
    }
}

/*
*   This function is used to calculate the total number of factors
*   for a number which we get by multiplying all the numbers
*   in the given array
*/
int totalNumberOfFactors(int a[], int n) {

    // * Initializing variables
    int ans = 1;
    unordered_map<int, int> freqFactorMap;

    // * Checking each element of the array
    for(int i=0; i<n; i++) {

        /*
        *   While the current element is more than 1,
        *   increment the frequency of it's lowest prime factor by 1.
        *   Also, reduce the number by dividing it with the lowest prime factor
        */
        while(a[i]>1) {
            freqFactorMap[prime[a[i]]]++;
            a[i] = a[i] / prime[a[i]];
        }
    }

    // * Iterating the map and calculating the answer
    for(unordered_map<int, int>::iterator it = freqFactorMap.begin(); it!=freqFactorMap.end(); it++) {
        ans *= (it->second+1);
    }

    // * Returning the answer
    return ans;
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
    int numberOfTestCases, numberOfIntegers, a[10];

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Generating the minimum prime factors for each number uptil 10^6
    generateMinimumPrimeFactors();

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the number of integers for the current test case
        cin>>numberOfIntegers;

        // * Accepting each integer one by one
        for(int i=0; i<numberOfIntegers; i++) {
            cin>>a[i];
        }

        /*
        *   Calculating the total number of factors for
        *   the current array and displaying it
        */
        cout<<totalNumberOfFactors(a, numberOfIntegers)<<endl;
    }
}