/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef SEAVOTE Problem
*   Problem Link:- https://www.codechef.com/problems/SEAVOTE
*	Website:- www.programmingvidya.com
*/
#include <iostream>
using namespace std;

int main() {

	// * Initializing variables
	int numberOfTestCases, numberOfOpinions, sum, count, i, b[10000];
	bool valid;

	// * Accepting the number of test cases
	cin>>numberOfTestCases;

	// * Executing each test case one by one
	while(numberOfTestCases--) {

		// * Accepting the number of opinions for the current test case
	    cin>>numberOfOpinions;

		// * Initializing sum, count to 0 and valid to true for the current test case
	    sum=0;
	    count = 0;
	    valid = true;

		// * Accepting the statistics B one by one for n opinions
	    for(i=0; i<numberOfOpinions; i++) {

			// * Accepting the value of statistics B for the current opinion
	        cin>>b[i];

			/*
			*	If the current value is more than 100,
			*	no valid value for A exists, break the loop
			*/
	        if(b[i]>100) {
	            valid = false;
	        }

			/*
			*	If the current value is more than 0
			*	increment the count by 1 as we're going to consider
			*	this value for final calculation
			*/
	        if(b[i]>0) {
	            count++;
	        }

			// * Adding the current value to the sum
	        sum += b[i];
	    }

		/*
		*	If a valid statistics A exists for the current value of B,
		*	and (total sum of statistics B - 100) >= 0
		*	and (total sum of statistics B - 100) < count
		*	print "YES"
		*/
	    if(valid && sum-100 >= 0 && sum-100 < count) {
	        cout<<"YES"<<endl;
	    }

		// * Otherwise, print "NO"
		else {
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
