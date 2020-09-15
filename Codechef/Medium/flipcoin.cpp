/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef FLIPCOIN Problem
*   Problem Link:- https://www.codechef.com/problems/FLIPCOIN
*   Website:- www.programmingvidya.com
*/
#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

// * Class to create a segment tree
class SegmentTree {

    // * Initializing variables
    vector<int> st;
    int size;

    // * Function to build a segment tree
    void build(int start, int end, int index) {

        // * Base Case - Leaf Node - Initialize with value 0
        if(start==end) {
            st[index] = 0;
            return;
        }

        // * Recursive Case

        // * Calculating the mid point
        int mid = (start+end)>>1;

        // * Building Left Sub Tree
        build(start, mid, (index<<1) + 1);

        // * Building Right Sub Tree
        build(mid+1, end, (index<<1) + 2);

        /*
        *   Setting up the value at current index
        *   based on the left and right child node values
        */
        st[index] = st[(index<<1)+1] + st[(index<<1)+2];
    }

    public:

    // * Defining a constructor to build segment tree
    SegmentTree(int n) {
        size = 4*n;
        st.reserve(size);
        build(0, n-1, 0);
    }

    // * Method to lazy update the values in range
    void updateRange(int lazy[], int start, int end, int l, int r, int index = 0) {

        // * If the current index is marked as lazy
        if(lazy[index]) {

            // * Update the value for current index
            st[index] = (end-start+1) - st[index];

            // * Mark children for lazy update
            if(start!=end) {
                lazy[(index<<1) + 1] = 1 - lazy[(index<<1) + 1];
                lazy[(index<<1) + 2] = 1 - lazy[(index<<1) + 2];
            }

            // * Remove the current index from lazy update array
            lazy[index] = 0;
        }

        // * Out of Range
        if(end<l || start>r) {
            return;
        }

        // * Full Overlap
        if(start>=l && end<=r) {

            // * Update the value for current index
            st[index] = (end-start+1) - st[index];

            // * Mark children for Lazy Update and return
            if(start!=end) {
                lazy[(index<<1) + 1] = 1 - lazy[(index<<1) + 1];
                lazy[(index<<1) + 2] = 1 - lazy[(index<<1) + 2];
            }

            return;
        }

        // * Partial Overlap
        int mid = (start+end)>>1;

        // * Update nodes in left subtree
        updateRange(lazy, start, mid, l, r, (index<<1) + 1);

        // * Update nodes in right subtree
        updateRange(lazy, mid+1, end, l, r, (index<<1) + 2);

        // * Update the value at current index
        st[index] = st[(index<<1)+1] + st[(index<<1)+2];
    }

    // * Method to lazy query the values in range
    int queryRange(int lazy[], int start, int end, int l, int r, int index = 0) {

        // * Out of Range
        if(end<l || start>r) {
            return 0;
        }

        // * If the current index is marked as lazy
        if(lazy[index]) {

            // * Update the value for current index
            st[index] = (end-start+1) - st[index];

            // * Mark children for lazy update
            if(start!=end) {
                lazy[(index<<1) + 1] = 1 - lazy[(index<<1) + 1];
                lazy[(index<<1) + 2] = 1 - lazy[(index<<1) + 2];
            }

            // * Remove the current index from lazy update array
            lazy[index] = 0;
        }

        // * Full Overlap
        if(start>=l && end<=r) {

            // * Return the value for current index
            return st[index];
        }

        // * Partial Overlap
        int mid = (start+end)>>1;

        // * Getting value from left subtree
        int left = queryRange(lazy, start, mid, l, r, (index<<1) + 1);

        // * Getting value from right subtree
        int right = queryRange(lazy, mid+1, end, l, r, (index<<1) + 2);

        // * Returning the sum of values from left and right subtree
        return left + right;
    }

    // * Method to display the Segment Tree
    void display() {
        for(int i=0; i<size; i++) {
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }
};

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
    int n, q, x, a, b;

    // * Accepting the number of elements and number of queries
    cin>>n>>q;

    /*
    *   Creating a segment tree with n 0s and
    *   initializing the lazy array of size (4*n) with 0
    */
    SegmentTree s(n);
    int lazy[4*n] = {0};

    // * Executing each query one by one
    while(q--) {

        // * Accepting the values for type of operation and the range endpoints A and B
        cin>>x>>a>>b;

        // * If x==1
        if(x) {

            // * Display elements in range a to b
            cout<<s.queryRange(lazy, 0, n-1, a, b)<<endl;
        } else {

            // * Update elements in range a to b
            s.updateRange(lazy, 0, n-1, a, b);
        }
    }
}