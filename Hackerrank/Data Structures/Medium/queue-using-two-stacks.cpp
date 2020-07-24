/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Queue using Two Stacks problem
*   Problem Link:- https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
*/
#include <iostream>
#include <stack>
using namespace std;

/*
*   This method is used to shift all the elements from
*   push stack to pop stack
*/
void shiftElementsFromPushStackToPopStack(stack<int> &pushStack, stack<int> &popStack) {

    // * While push stack is not empty
    while(!pushStack.empty()) {

        /*
        *   Getting the top element from push stack
        *   and pushing it into pop stack
        */
        popStack.push(pushStack.top());

        // * Removing the top element from push stack
        pushStack.pop();
    }
}

int main() {

    // * Initializing variables
    int queries, choice, element;
    stack<int> pushStack, popStack;

    // * Accepting the number of queries
    cin>>queries;

    // * Considering each query one by one
    while(queries--) {

        // * Accepting the choice for each query
        cin>>choice;

        // * If choice is equal to 1
        if(choice == 1) {

            // * Accepting the element to insert
            cin>>element;

            // * Inserting element into push stack
            pushStack.push(element);
        }

        // * If choice is equal to 2
        else if(choice == 2) {

            /*
            *   If pop stack is empty,
            *   shift the elements from push stack to pop stack
            */
            if(popStack.empty()) {
                shiftElementsFromPushStackToPopStack(pushStack, popStack);
            }

            // * Removing the top element from pop stack
            popStack.pop();
        }

        // * If choice is equal to 3
        else if(choice == 3) {

            /*
            *   If pop stack is empty,
            *   shift the elements from push stack to pop stack
            */
            if(popStack.empty()) {
                shiftElementsFromPushStackToPopStack(pushStack, popStack);
            }

            // * Displaying the top element in pop stack
            cout<<popStack.top()<<endl;
        }
    }
    return 0;
}