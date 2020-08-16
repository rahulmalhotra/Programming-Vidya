/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Learning about Stack in C++
*   Website:- www.programmingvidya.com
*   YouTube Video:- https://youtu.be/a1z6YMtLP6Y
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Initializing Variables
    stack<int> s;
    int element;

    // * Push Operation
    cin>>element;
    while(element!=0) {
        s.push(element);
        cin>>element;
    }

    // * Display the number of elements in stack
    cout<<"Total number of elements in stack = "<<s.size()<<endl;

    // * Pop operation
    while(!s.empty()) {
        cout<<"Topmost Element in Stack = "<<s.top()<<endl;
        s.pop();
        cout<<"Size of Stack = "<<s.size()<<endl;
    }

}