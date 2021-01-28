/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank QHEAP1 problem
*   Problem Link:- https://www.hackerrank.com/challenges/qheap1/problem
*   Website:- www.programmingvidya.com
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    // * Initializing variables
    set<int> heap;
    int q, type, v;

    // * Accepting the number of queries
    cin>>q;

    // * Executing each query one by one
    while(q--) {

        // * Accepting the type of the query
        cin>>type;

        // * If type is 1
        if(type==1) {

            // * Accept the element v and add it to the heap
            cin>>v;
            heap.insert(v);
        }

        // * Otherwise, if type is 2
        else if(type==2) {

            // * Accept the element v and delete it from the heap
            cin>>v;
            heap.erase(v);
        }

        // * Otherwise, print the minimum of all the elements in the heap
        else {
            cout<<*heap.begin()<<endl;
        }
    }

    return 0;
}