#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class segmenttree {

    public:
    vector<int> st;

    segmenttree(int n) {
        st.reserve(4*n);
    }

    void build(int a[], int start, int end, int index) {

        if(start==end) {
            st[index] = a[start];
            return;
        }

        // calculating mid
        int mid = (start + end)/2;

        // left build
        build(a, start, mid, 2*index + 1);

        // right build
        build(a, mid+1, end, 2*index + 2);

        st[index] = st[index*2+1] + st[index*2+2];

        return;
    }

    int query(int start, int end, int l, int r, int index) {

        // no overlap
        if(l>end || r<start) {
            return 0;
        }

        // full overlap
        if(start>=l && end<=r) {
            return st[index];
        }

        // partial overlap
        int mid = (start+end)/2;

        // left query
        int left = query(start, mid, l, r, 2*index + 1);

        // right query
        int right = query(mid+1, end, l, r, 2*index + 2);

        return left + right;
    }

    void update(int a[], int start, int end, int indexToUpdate, int value, int index) {

        if(start==end) {
            st[indexToUpdate] = value;
            a[indexToUpdate] = value;
            return;
        }

        int mid = (start+end)/2;

        if(indexToUpdate<=mid) {
            // move to left sub tree
            update(a, start, mid, indexToUpdate, value, 2*index + 1);
        } else {
            // move to right sub tree
            update(a, mid+1, end, indexToUpdate, value, 2*index + 2);
        }

        st[index] = st[2*index + 1] + st[index*2 + 2];

        return;
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

    /*
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    segmenttree tree(n);
    tree.build(a, 0, n-1, 0);

    for(int i=0; i<4*n; i++) {
        cout<<tree.st[i]<<" ";
    }

    cout<<endl;
    cout<<tree.query(0, n-1, 0, 7, 0)<<endl;
    cout<<tree.query(0, n-1, 1, 7, 0)<<endl;
    cout<<tree.query(0, n-1, 5, 5, 0)<<endl;

    tree.update(a, 0, 7, 0, 2, 0);
    cout<<tree.query(0, n-1, 0, 7, 0)<<endl;
    */

    int n, q, x, a, b, val;
    cin>>n>>q;

    int arr[n] = {0};

    segmenttree tree(n);
    tree.build(arr, 0, n-1, 0);

    while(q--) {
        cin>>x>>a>>b;
        if(x==0) {
            for(int i=a; i<=b; i++) {
                cout<<arr[i]<<" ";
                val = 0;
                if(arr[i]==0) {
                    val = 1;
                }
                tree.update(arr, 0, n-1, i, val, 0);
            }
            cout<<endl;
        } else {
            cout<<tree.query(0, n-1, a, b, 0)<<endl;
        }
    }
}