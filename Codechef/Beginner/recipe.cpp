/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RECIPE Problem
*   Problem Link:- https://www.codechef.com/problems/RECIPE
*	Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

// * This function is used to return the gcd of two numbers
int gcd(int a, int b) {
	if(b==0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
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

    // * Initializing the variables
    int numberOfTestCases, numberOfIngredients, ingredientsGCD, ingredients[50];

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

    	// * Accepting the number of incredients for the current test case
    	cin>>numberOfIngredients;

    	/*
    	*	Accepting the quantity of first ingredient and
    	*	storing it in ingredientsGCD
    	*/
    	cin>>ingredients[0];
    	ingredientsGCD = ingredients[0];

    	/*
    	*	Accepting the rest of the ingredients and
    	*	finding the GCD of quantities of ingredients
    	*/
    	for(int i=1; i<numberOfIngredients; i++) {
    		cin>>ingredients[i];
    		ingredientsGCD = gcd(ingredientsGCD, ingredients[i]);
    	}

    	/*
    	*	Displaying the quantity of each ingredient that
    	*	the chef should use in order to make as little food as possible.
    	*/
    	for(int i=0; i<numberOfIngredients;  i++) {
    		cout<<ingredients[i]/ingredientsGCD<<" ";
    	}

    	// * Displaying a new line before executing the next test case
    	cout<<endl;
    }
}