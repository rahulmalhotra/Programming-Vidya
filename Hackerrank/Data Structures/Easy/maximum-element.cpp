/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Maximum Element Problem
*   Problem Link:- https://www.hackerrank.com/challenges/maximum-element/problem
*   Website:- www.programmingvidya.com
*   YouTube Video:- https://youtu.be/FCYSpvKzHvw
*   Basic Idea:- Prepare a max stack which will tell you the maximum
*                element in the original stack at any instant
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    *   Remove this code if you're going to submit on HackerRank - Start
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // * Remove this code if you're going to submit on HackerRank - End

    // * Initializing variables
    stack<int> s, maxStack;
    int numberOfQueries, typeOfQuery, x;

    // * Accepting the number of queries
    cin>>numberOfQueries;

    // * Executing each query one by one
    while(numberOfQueries--) {

        // * Accepting the type of query
        cin>>typeOfQuery;

        // * If Query type = 1, push the element x into the stack
        if(typeOfQuery==1) {

            // * Accepting the element x and pushing it to the stack
            cin>>x;
            s.push(x);

            /*
            *   If max stack is empty or the current element 'x' is greater
            *   than the top element of max stack, push the current element
            *   into max stack. Otherwise, push the top element
            *   of max stack into the max stack
            */
            if(
                maxStack.empty() ||
                x > maxStack.top()
            ) {
                maxStack.push(x);
            } else {
                maxStack.push(maxStack.top());
            }
        }

        /*
        *   If Query type = 2, pop the element from the top of stack.
        *   Also, pop the element from the top of max stack
        */
        else if(typeOfQuery==2) {
            s.pop();
            maxStack.pop();
        }

        // * If Query type = 3, display the top most element of the max stack
        else if(typeOfQuery==3) {

            // * Display Maxium Element in Stack
            cout<<maxStack.top()<<endl;
        }
    }

    return 0;
}