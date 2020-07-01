/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Jumping on the Clouds: Revisited problem
*   Problem Link:- https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem
*/
int jumpingOnClouds(vector<int> c, int k) {

    // * Initializing variables
    int energy = 100, n = c.size(), i = 0;

    do {

        // * Updating the index after each step
        i = (i+k)%n;

        /*
        *   Decreasing the energy by 1 after each step
        *   as a cost of each jump
        */
        energy -= 1;

        /*
        *   In case the current cloud is a thunder cloud,
        *   decreasing the energy by 2
        */
        if(c[i]==1) {
            energy -= 2;
        }

        /*
        *   This loop will continue untill we
        *   reach the original position i.e. index 0
        */

    } while(i!=0);

    // * Return remaining energy
    return energy;
}