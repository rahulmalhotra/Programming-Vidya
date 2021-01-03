/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Median Updates problem
*   Problem Link:- https://www.hackerrank.com/challenges/median/problem
*   Website:- www.programmingvidya.com
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
/* Head ends here */

void median(vector<char> s,vector<int> X) {

    /*
    *   Initializing variables.
    *   Creating two multisets to store the left half
    *   and right half of the list in a sorted order
    */
    multiset<long int> leftSet, rightSet;
    int length = s.size();
    double median = 0;

    // * Checking each operation one by one
    for(int i=0; i<length; i++) {

        // * If a number is added to the list
        if(s[i]=='a') {

            /*
            *   If both the sets are empty,
            *   insert the number to the left set and
            *   mark it as the median
            */
            if(leftSet.empty() && rightSet.empty()) {
                leftSet.insert(X[i]);
                median = X[i];
            }

            // * Otherwise, if left set has more numbers than right set
            else if(leftSet.size()>rightSet.size()) {

                /*
                *   If the current number is less than the current median,
                *   this means, it should go to the left set. As the left set
                *   has already more numbers than the right set, we're going to
                *   shift the maximum or last number of the left set to the right set.
                *   Finally, we're going to insert the current number to the left set
                *   so that both the sets have equal numbers
                */
                if(X[i]<median) {
                    rightSet.insert(*(--leftSet.end()));
                    leftSet.erase(--leftSet.end());
                    leftSet.insert(X[i]);
                }

                /*
                *   Otherwise, if the current number is greater than or equal to median,
                *   it should go to the right set. As the right set has less numbers
                *   than left set, just insert the current number to right set
                *   and both the sets have equal numbers now
                */
                else {
                    rightSet.insert(X[i]);
                }

                /*
                *   As both the sets have equal numbers, this means that
                *   we have even numbers in the list. Calculating the median
                *   as the average of the middle two numbers i.e. the last number of
                *   the left set and first number of the right set
                */
                median = (*(--leftSet.end()) + *rightSet.begin()) / 2.0;
            }

            // * Otherwise, if left set has less numbers than right set
            else if(leftSet.size()<rightSet.size()) {

                /*
                *   If the current number is less than the current median,
                *   this means, it should go to the left set. As the left set
                *   has less numbers than the right set, just insert
                *   the current number to the left set and
                *   both the sets have equal numbers now
                */
                if(X[i]<median) {
                    leftSet.insert(X[i]);
                }

                /*
                *   Otherwise, if the current number is greater than or equal
                *   to the current median, this means it should go to the right set.
                *   As the right set has already more numbers than the left set,
                *   we're going to shift the minimum or first number of the right set
                *   to the left set. Finally, we're going to insert the current number
                *   to the right set and both the sets have equal numbers now
                */
                else {
                    leftSet.insert(*rightSet.begin());
                    rightSet.erase(rightSet.begin());
                    rightSet.insert(X[i]);
                }

                /*
                *   As both the sets have equal numbers, this means that
                *   we have even numbers in the list. Calculating the median
                *   as the average of the middle two numbers i.e. the last number of
                *   the left set and first number of the right set
                */
                median = (*(--leftSet.end()) + *rightSet.begin()) / 2.0;
            }

            // * Otherwise, if both the left set and right set have equal numbers
            else {

                /*
                *   If the current number is less than median,
                *   insert it into the left set and update the median
                *   as the last or maximum number of the left set
                */
                if(X[i]<median) {
                    leftSet.insert(X[i]);
                    median = *(--leftSet.end());
                }

                /*
                *   Otherwise, if the current number is greater than
                *   or equal to median, insert it into the right set
                *   and update the median as the first or
                *   minimum number of the right set
                */
                else {
                    rightSet.insert(X[i]);
                    median = *rightSet.begin();
                }
            }
        }

        // * Otherwise, if a number is removed from the list
        else {

            /*
            *   If the number which is removed
            *   is not found in any of the left set or right set,
            *   print "Wrong!" and continue to the next operation
            */
            if(
                leftSet.find(X[i])==leftSet.end() &&
                rightSet.find(X[i])==rightSet.end()
            ) {
                cout<<"Wrong!"<<endl;
                continue;
            }

            // * Otherwise, if left set has more numbers than right set
            else if(leftSet.size()>rightSet.size()) {

                /*
                *   If the current number is present in the left set,
                *   simply remove it from the left set so that
                *   both the sets have equal numbers
                */
                if(leftSet.find(X[i])!=leftSet.end()) {
                    leftSet.erase(leftSet.find(X[i]));
                }

                /*
                *   Otherwise, if the current number is present in the right set,
                *   as the left set has more numbers than the right set,
                *   shift the maximum or last number from the left set to
                *   the right set and remove the current number from the right set
                *   so that both the sets have equal numbers
                */
                else if(rightSet.find(X[i])!=rightSet.end()) {
                    rightSet.insert(*(--leftSet.end()));
                    leftSet.erase(--leftSet.end());
                    rightSet.erase(rightSet.find(X[i]));
                }

                /*
                *   If the both the sets are empty,
                *   display "Wrong!" as the median cannot be calculated
                *   and move on to the next operation
                */
                if(leftSet.empty() && rightSet.empty()) {
                    cout<<"Wrong!"<<endl;
                    continue;
                }

                /*
                *   As both the sets have equal numbers, this means that
                *   we have even numbers in the list. Calculating the median
                *   as the average of the middle two numbers i.e. the last number of
                *   the left set and first number of the right set
                */
                median = (*(--leftSet.end()) + *rightSet.begin()) / 2.0;
            }

            // * Otherwise, if left set has less numbers than right set
            else if(leftSet.size()<rightSet.size()) {

                /*
                *   If the current number is present in the left set,
                *   as the right set has more numbers than the left set,
                *   shift the minimum or first number from the right set to
                *   the left set and remove the current number from the left set
                *   so that both the sets have equal numbers
                */
                if(leftSet.find(X[i])!=leftSet.end()) {
                    leftSet.insert(*rightSet.begin());
                    rightSet.erase(rightSet.begin());
                    leftSet.erase(leftSet.find(X[i]));
                }

                /*
                *   Otherwise, if the current number is present in the right set,
                *   simply remove it from the right set so that
                *   both the sets have equal numbers
                */
                else {
                    rightSet.erase(rightSet.find(X[i]));
                }

                /*
                *   If the both the sets are empty,
                *   display "Wrong!" as the median cannot be calculated
                *   and move on to the next operation
                */
                if(leftSet.empty() && rightSet.empty()) {
                    cout<<"Wrong!"<<endl;
                    continue;
                }

                /*
                *   As both the sets have equal numbers, this means that
                *   we have even numbers in the list. Calculating the median
                *   as the average of the middle two numbers i.e. the last number of
                *   the left set and first number of the right set
                */
                median = (*(--leftSet.end()) + *rightSet.begin()) / 2.0;
            }

            // * Otherwise, if both the sets have equal numbers
            else {

                // * If the number is present in the left set
                if(leftSet.find(X[i])!=leftSet.end()) {

                    // * Remove it from the left set
                    leftSet.erase(leftSet.find(X[i]));

                    /*
                    *   If the right set is not empty,
                    *   set the median as the first number
                    *   of the right set
                    */
                    if(!rightSet.empty()) {
                        median = *rightSet.begin();
                    }

                    /*
                    *   Otherwise, display "Wrong!"
                    *   as the list is empty and
                    *   move on to the next operation
                    */
                    else {
                        cout<<"Wrong!"<<endl;
                        continue;
                    }
                }

                // * Otherwise, if the number is present in the right set
                else if(rightSet.find(X[i])!=rightSet.end()) {

                    // * Remove it from the right set
                    rightSet.erase(rightSet.find(X[i]));

                    /*
                    *   If the left set is not empty,
                    *   set the median as the last number
                    *   of the left set
                    */
                    if(!leftSet.empty()) {
                        median = *(--leftSet.end());
                    }

                    /*
                    *   Otherwise, display "Wrong!"
                    *   as the list is empty and
                    *   move on to the next operation
                    */
                    else {
                        cout<<"Wrong!"<<endl;
                        continue;
                    }
                }
            }
        }

        /*
        *   If the median is an integer,
        *   display it without the trailing 0 and decimal.
        *   Otherwise, display it
        *   with one digit after decimal
        */
        cout<<fixed;
        cout<<setprecision(1);
        if(median == (int)median) {
            cout<<(int)median<<endl;
        } else {
            cout<<median<<endl;
        }
    }
}

// * Main function as given by HackerRank
int main(void){

//Helpers for input and output

	int N;
	cin >> N;

	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}

	median(s,X);
	return 0;
}
