/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Waiter Problem
*   Problem Link:- https://www.hackerrank.com/challenges/waiter/problem
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <stack>
#include <vector>
using namespace std;

// * This variable will store 1200 prime numbers
int prime[1201];

// * Function to generate 1200 prime numbers and store them in prime array
void generatePrimes() {

    // * Initializing variables
    bitset<10000> isPrime;
    int count = 1, i = 2;

    // * Initially, mark all the numbers as prime
    isPrime.set();

    // * Store 1200 prime numbers in prime array
    for(int i=2; i<=9735; i++) {

        // * If the current number is prime
        if(isPrime.test(i)) {

            // * Store it in the prime array
            prime[count] = i;

            // * Increment the number of primes by 1
            count++;

            // * Mark all the other numbers that are divisible by current number as not prime
            for(int j=i; j<=9735; j+=i) {
                isPrime.set(j, 0);
            }
        }
    }
}

/*
 * Complete the waiter function below.
 */
vector<int> waiter(vector<int> number, int q) {

    // * Initializing the variables
    int x, numsize = number.size();
    vector<stack<int> > a, b;
    vector<int> result;
    stack<int> s;

    // * Generating 1200 prime numbers and storing them in prime array
    generatePrimes();

    // * Pushing the input into the stack s
    for(int i=0; i<numsize; i++)
    {
        s.push(number[i]);
    }

    // * Adding input stack s to first index of vector a
    a.push_back(s);

    /*
    *   Blocking the first index of vector b as well
    *   by adding input stack s as it's not required
    */
    b.push_back(s);

    // * Executing each query one by one
    for(int i=1; i<=q; i++) {

        // * Initializing two stacks sa and sb to be used for pile a[i] and b[i]
        stack<int> sa, sb;

        // * Getting the pile a[i-1]
        s = a[i-1];

        // * Looping while the pile is not empty
        while(!s.empty()) {

            // * Getting the number on the topmost plate of the pile
            x = s.top();

            // * Remove the plate from the current pile
            s.pop();

            // * If the number is divisible by ith prime, push the plate into stack sb
            if(x%prime[i]==0) {
                sb.push(x);
            }

            // * Otherwise, push it into stack sa
            else {
                sa.push(x);
            }

        }

        /*
        *   Setup the stack sa as the pile a[i],
        *   as vector a is already filled until index i-1
        */
        a.push_back(sa);

        /*
        *   Setup the stack sb as the pile b[i],
        *   as vector b is filled until index i-1
        */
        b.push_back(sb);

    }

    /*
    *   Getting the numbers on each pile B1...Bq from top to bottom
    *   and pushing them to the result vector
    */
    for(int i=1; i<=q; i++) {

        // * Getting the b[i] pile
        s = b[i];

        /*
        *   While the pile is not empty,
        *   pick up the plates one by one
        *   and push the number written on it
        *   into the result vector
        */
        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
    }

    // * Getting the a[q] pile
    s = a[q];

    /*
    *   While the pile is not empty,
    *   pick up the plates one by one
    *   and push the number written on it
    *   into the result vector
    */
    while(!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    // * Returning the result vector
    return result;
}

int main() {

    // * Remove this before submitting on HackerRank - Start
    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // * Remove this before submitting on HackerRank - End

    // * Initializing variables
    vector<int> numbers;
    int n, q, x;

    // * Accepting the values for n and q
    cin>>n>>q;

    // * Accepting each number one by one and pushing them to the numbers vector
    for(int i=0; i<n; i++) {
        cin>>x;
        numbers.push_back(x);
    }

    /*
    *   Getting the result vector from waiter function and
    *   calculating the size of result vector
    */
    vector<int> result = waiter(numbers, q);
    int resultSize = result.size();

    // * Displaying the result vector
    for(int i=0; i<resultSize; i++) {
        cout<<result[i]<<endl;
    }
}