/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef MULTQ3 Problem
*   Problem Link:- https://www.codechef.com/problems/MULTQ3
*	Website:- www.programmingvidya.com
*/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/*
*   Initializing a class trio to store the
*   count of numbers having remainders as
*   zero, one and two when divided by 3
*/
class trio {

    public:

    int zero;
    int one;
    int two;

    trio(int zero, int one, int two) {
        this->zero = zero;
        this->one = one;
        this->two = two;
    }
};

// * Creating the Segment Tree class
class SegmentTree {

    // * Initializing the data members
    vector<trio> st;
    vector<int> lazy;
    int size;

    // * This method is used to build the segment tree
    void build(int start, int end, int index) {

        // * Base Case - Leaf Node initialization
        if(start==end) {
            trio t(1, 0, 0);
            st[index] = t;
            return;
        }

        // * Calculating the mid
        int mid = (start+end)>>1;

        // * Building the left subtree
        build(start, mid, (index<<1) + 1);

        // * Building the right subtree
        build(mid+1, end, (index<<1) + 2);

        // * Setting up the value at current index in the tree
        st[index].zero = st[(index<<1) + 1].zero + st[(index<<1) + 2].zero;
        st[index].one = 0;
        st[index].two = 0;
    }

    public:

    // * Constructor
    SegmentTree(int n) {

        /*
        *   Calculating the tree size and
        *   reserving the segment tree and
        *   lazy vectors according to the size
        */
        size = n*4;
        lazy.reserve(size);
        st.reserve(size);

        // * Building the segment tree
        build(0, n-1, 0);

        // * Initializing all elements in lazy vector to 0
        for(int i=0; i<size; i++) {
            lazy[i] = 0;
        }
    }

    // * This method is used to query a range in segment tree
    int queryRange(int start, int end, int l, int r, int index = 0) {

        // * Resetting the value in lazy array at the current index
        lazy[index] = lazy[index] % 3;

        /*
        *   If the lazy array has a value at current index
        *   and the element at current index is not a leaf node,
        *   update the lazy array for the children of the current node
        */
        if(lazy[index] && start!=end) {
            lazy[(index<<1)+1] += lazy[index];
            lazy[(index<<1)+2] += lazy[index];
        }

        /*
        *   Update the value of segment tree node according to the
        *   value of lazy array at the current index
        */
        while(lazy[index]) {
            int temp = st[index].two;
            st[index].two = st[index].one;
            st[index].one = st[index].zero;
            st[index].zero = temp;
            lazy[index]--;
        }

        // * If we're going out of range, return 0
        if(end<l || start>r) {
            return 0;
        }

        /*
        *   If we're in the range,
        *   return the number of elements
        *   that are fully divisible by 3
        */
        if(start>=l && end<=r) {
            return st[index].zero;
        }

        // * Calculating the mid point in the current range
        int mid = (start + end) >> 1;

        /*
        *   Getting the number of elements divisible by 3
        *   from the part of queried range lying in the left subtree
        */
        int left = queryRange(start, mid, l, r, (index<<1) + 1);

        /*
        *   Getting the number of elements divisible by 3
        *   from the part of queried range lying in the right subtree
        */
        int right = queryRange(mid+1, end, l, r, (index<<1) + 2);

        // * Returning the total number of elements divisible by 3
        return left + right;
    }

    // * This method is used to update a range in the segment tree
    void updateRange(int start, int end, int l, int r, int index = 0) {

        // * Updating the lazy array at the current index
        lazy[index] = lazy[index] % 3;

        /*
        *   If the lazy array has a value at current index
        *   and the node at current index is not a leaf node,
        *   update the lazy array for the children of the current node
        */
        if(lazy[index] && start!=end) {
            lazy[(index<<1)+1] += lazy[index];
            lazy[(index<<1)+2] += lazy[index];
        }

        /*
        *   Update the value of segment tree node according to the
        *   value of lazy array at the current index
        */
        while(lazy[index]) {
            int temp = st[index].two;
            st[index].two = st[index].one;
            st[index].one = st[index].zero;
            st[index].zero = temp;
            lazy[index]--;
        }

        /*
        *   If we're going out of range, return
        *   as we don't need to update anything here
        */
        if(end<l || start>r) {
            return;
        }

        /*
        *   If we're in the range,
        *   update the node at the current index
        *   and update the lazy array for value
        *   for the child nodes
        */
        if(start>=l && end<=r) {

            int temp = st[index].two;
            st[index].two = st[index].one;
            st[index].one = st[index].zero;
            st[index].zero = temp;

            if(start!=end) {
                lazy[(index<<1)+1]++;
                lazy[(index<<1)+2]++;
            }

            return;
        }

        // * Calculating the mid point in the current range
        int mid = (start+end)>>1;

        /*
        *   Updating the number of elements
        *   within the range to update in the left subtree
        */
        updateRange(start, mid, l, r, (index<<1) + 1);

        /*
        *   Updating the number of elements
        *   within the range to update in the right subtree
        */
        updateRange(mid+1, end, l, r, (index<<1) + 2);

        // * Updating the current node by using the child nodes
        trio a = st[(index<<1) + 1];
        trio b = st[(index<<1) + 2];
        st[index].zero = a.zero + b.zero;
        st[index].one = a.one + b.one;
        st[index].two = a.two + b.two;
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

    // * Initializing variables
    int n, q, x, a, b;

    // * Accepting the number of elements and the number of queries
    scanf("%d %d", &n, &q);

    // * Initializing the segment tree for the current number of elements
    SegmentTree st(n);

    // * Executing each query one by one
    while(q--) {

        // * Accepting the type of query and the range
        scanf("%d %d %d", &x, &a, &b);

        /*
        *   If the type of query is 1,
        *   query the elements in the range. Otherwise,
        *   update the elements in the range
        */
        if(x) {
            printf("%d\n", st.queryRange(0, n-1, a, b));
        } else {
            st.updateRange(0, n-1, a, b);
        }
    }

	return 0;
}