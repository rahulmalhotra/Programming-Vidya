/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef PTMSSNG Problem (July Long Challenge 2020)
*   Problem Link:- https://www.codechef.com/JULY20B/problems/PTMSSNG
*/
#include <iostream>
#include <stdio.h>
#include <map>
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

    // * Enabling fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // * Initializing variables
    int t, n, finalX = 0, finalY = 0, x, y;

    // * Accepting the number of test cases
    cin>>t;

    // * Considering each test case one by one
    while(t--) {

        // * Initializing xMap and yMap
        map<int, int> xMap, yMap;

        // * Accepting the value of n
        cin>>n;

        /*
        *   Accepting (4n-1) vertices and incrementing the number of
        *   points lying on the corresponding x and y axis in xMap and yMap
        */
        for(int i=0; i<4*n-1; i++) {
            cin>>x>>y;
            xMap[x]++;
            yMap[y]++;
        }

        /*
        *   Iterating xMap to find the x-axis where the number of points
        *   lying on the axis are odd and storing it in finalX
        */
        for (map<int,int>::iterator it=xMap.begin(); it!=xMap.end(); ++it) {
            if(it->second&1) {
                finalX = it->first;
                break;
            }
        }

        /*
        *   Iterating yMap to find the y-axis where the number of points
        *   lying on the axis are odd and storing it in finalY
        */
        for (map<int,int>::iterator it=yMap.begin(); it!=yMap.end(); ++it) {
            if(it->second&1) {
                finalY = it->first;
                break;
            }
        }

        /*
        *   Displaying the final x-axis and final y-axis
        *   i.e. the coordinates of missing point
        */
        cout<<finalX<<" "<<finalY<<endl;
    }
}