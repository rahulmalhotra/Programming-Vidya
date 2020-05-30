/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef TABLET Problem
*   Problem Link:- https://www.codechef.com/problems/TABLET
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, numberOfTablets, budget, width, height, price, maxArea;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Initializing maximum area to 0 for current test case
        maxArea = 0;

        // * Accepting the number of tablets and budget for current test case
        cin>>numberOfTablets>>budget;

        // * Looping the number of tablets
        for(int i=0; i<numberOfTablets; i++) {

            // * Accepting width, height and price for current tablet
            cin>>width>>height>>price;

            /*
            *   If price of the current tablet is under budget,
            *   we update the maximum area if the area of current tablet
            *   is greater than the current maximum area
            */
            if(price<=budget) {
                maxArea = max(maxArea, width*height);
            }
        }

        /*
        *   Displaying no tablet if maximum area is still 0
        *   Otherwise, displaying the value of maximum area
        */
        if(maxArea==0) {
            cout<<"no tablet"<<endl;
        } else {
            cout<<maxArea<<endl;
        }
    }
}