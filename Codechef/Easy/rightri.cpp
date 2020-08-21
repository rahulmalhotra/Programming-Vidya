/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef RIGHTRI Problem
*   Problem Link:- https://www.codechef.com/problems/RIGHTRI
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
using namespace std;

/*
*   This method is used to return if a triangle is a
*   right-angled triangle or not, based on the given coordinates
*/
bool isRightTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {

    // * Calculating square of side 1
    int d1 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

    // * Calculating square of side 2
    int d2 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);

    // * Calculating square of side 3
    int d3 = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);

    /*
    *   If the sum of square of any two sides
    *   is equal to the square of third side,
    *   return true, as the triangle is a
    *   right-angled triangle
    */
    if(
        (d1+d2) == d3 ||
        (d1+d3) == d2 ||
        (d3+d2) == d1
    ) {
        return true;
    }

    // * Otherwise, return false
    return false;
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
    int n, x1, y1, x2, y2, x3, y3, numberOfRightTriangles = 0;

    // * Accepting the number of triangles
    cin>>n;

    /*
    *   Accepting co-ordinates of each triangle one by one
    *   and checking if it's a right triangle. If yes,
    *   increment the number of right triangles by 1
    */
    while(n--) {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(isRightTriangle(x1, y1, x2, y2, x3, y3)) {
            numberOfRightTriangles++;
        }
    }

    // * Display the number of right triangles
    cout<<numberOfRightTriangles;
}