/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PPSUM Problem
*   Problem Link:- https://www.codechef.com/problems/PPSUM
*/
#include <iostream>
using namespace std;

/*
*   This method is used to return the sum based on the values of d and n
*/
int sum(int d, int n) {

    // * Initializing total to zero
    int total = 0;

    // * Calculating the sum of numbers from 1 to n and storing it in total
    for(int i=1; i<=n; i++) {
        total += i;
    }

    // * Base Case -> If d is equal to 1 return total
    if(d==1) {
        return total;
    }
    /*
    *   Recursive Case -> If d is not equal to 1,
    *   Call sum again with inputs d-1 (as sum should be called d times)
    *   and passing the total value as n for the next sum call
    */
    else {
        return sum(d-1, total);
    }
}

int main() {

    // * Initializing variables
    int numberOfTestCases, d, n;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the elements d and n for the current test case
        cin>>d>>n;

        // * Displaying the sum for the current test case
        cout<<sum(d,n)<<endl;
    }
}