/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PERMUT2 Problem
*   Problem Link:- https://www.codechef.com/problems/PERMUT2
*/
#include <iostream>
#include <stdio.h>
using namespace std;

/*
*	This function is used to calculate and return if the permutation
*	stored in an array is ambiguous or not
*/
bool isAmbiguousPermutation(int a[], int n) {
	for(int i=1; i<=n; i++) {
		if(a[a[i-1]-1]!=i) {
			return false;
		}
	}
	return true;
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
    int n, a[100000];

    // * Executing an infinite loop
    while(1) {

    	// * Accepting the value of n
    	cin>>n;

    	// * If n is equal to 0, break the loop
    	if(n==0) {
    		break;
    	}

    	// * Accepting the elements of array
    	for(int i=0; i<n; i++) {
    		cin>>a[i];
    	}

    	/*
    	*	If the elements of the array forms an ambiguous permutation,
    	*	print "ambiguous"
    	*/
    	if(isAmbiguousPermutation(a, n)) {
    		cout<<"ambiguous"<<endl;
    	}

    	// * Otherwise, print "non ambiguous"
    	else {
    		cout<<"not ambiguous"<<endl;
    	}
    }
}