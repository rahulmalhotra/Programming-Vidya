/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef GIFTSRC Problem
*   Problem Link:- https://www.codechef.com/problems/GIFTSRC
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, lengthOfInstructions, posX, posY;
    char instructions[1000], previousAxis, currentAxis = 'X';

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        // * Accepting the length of instructions for the current test case
        cin>>lengthOfInstructions;

        // * Accepting the instructions
        cin>>instructions;

        // * Setting up initial position of chef to (0,0) for the current test case
        posX=0;
        posY=0;

        /*
        *   Setting up the previous axis as Z for current test case
        *   so that initially, the current axis is different from the previous axis
        */
        previousAxis = 'Z';

        // * Considering each instruction one by one
        for(int i=0; i<lengthOfInstructions; i++) {

            // * Setting up the current axis based on the input
            if(instructions[i] == 'L' || instructions[i] == 'R') {
                currentAxis = 'X';
            } else if(instructions[i] == 'U' || instructions[i] == 'D') {
                currentAxis = 'Y';
            }

            /*
            *   If the current axis is equal to the previous axis,
            *   don't update anything and continue to next instruction
            */
            if(currentAxis == previousAxis) {
                continue;
            }

            /*
            *   If the current instruction is equal to L,
            *   decrease the position by 1 on the x - axis.
            *   If the current instruction is equal to R,
            *   increase the position by 1 on the x - axis.
            *   If the current instruction is equal to D,
            *   decrease the position by 1 on the y - axis.
            *   If the current instruction is equal to U,
            *   increase the position by 1 on the y - axis.
            */
            if(instructions[i] == 'L') {
                posX--;
            } else if(instructions[i] == 'R') {
                posX++;
            } else if(instructions[i] == 'D') {
                posY--;
            } else if(instructions[i] == 'U') {
                posY++;
            }

            // * Updating the previous axis with the value of current axis
            previousAxis = currentAxis;
        }

        /*
        *   Displaying position of cell (x, y) which contains the hidden gift
        *   for the current test case
        */
        cout<<posX<<" "<<posY<<endl;
    }
}