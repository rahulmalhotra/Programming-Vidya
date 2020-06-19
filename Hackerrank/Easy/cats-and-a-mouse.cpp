/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Cats and a Mouse Problem
*   Problem Link:- https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
*/
string catAndMouse(int x, int y, int z) {

    // * Calculating distance between Cat A and Mouse
    int distanceBetweenCatAAndMouse = abs(x-z);

    // * Calculating distance between Cat B and Mouse
    int distanceBetweenCatBAndMouse = abs(y-z);

    /*
    *   If distance between Cat A and Mouse is less than
    *   distance between Cat B and Mouse,
    *   Cat A will catch the mouse first
    */
    if(distanceBetweenCatAAndMouse < distanceBetweenCatBAndMouse) {
        return "Cat A";
    }
    /*
    *   If distance between Cat B and Mouse is less than
    *   distance between Cat A and Mouse,
    *   Cat B will catch the mouse first
    */
    else if(distanceBetweenCatAAndMouse > distanceBetweenCatBAndMouse) {
        return "Cat B";
    }
    /*
    *   Otherwise, both the cats will reach
    *   the mouse at the same time
    */
    else {
        return "Mouse C";
    }
}