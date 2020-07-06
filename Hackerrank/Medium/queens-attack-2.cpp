/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Queens Attack II problem
*   Problem Link:- https://www.hackerrank.com/challenges/queens-attack-2/problem
*/
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    // * Initializing variables
    int distance[8] = {0}, x, y, numberOfSquares = 0;
    float m;

    /*
    *   Initializing the initial distance the queen can travel in
    *   all 8 directions assuming that there is no obstacle
    */

    // * Distance in left direction
    distance[0] = c_q-1;
    // * Distance in top direction
    distance[1] = n-r_q;
    // * Distance in right direction
    distance[2] = n-c_q;
    // * Distance in bottom direction
    distance[3] = r_q-1;
    // * Distance in top-left direction
    distance[4] = min(distance[0], distance[1]);
    // * Distance in top-right direction
    distance[5] = min(distance[1], distance[2]);
    // * Distance in bottom-right direction
    distance[6] = min(distance[2], distance[3]);
    // * Distance in bottom-left direction
    distance[7] = min(distance[3], distance[0]);

    // * Iterating all obstacles one by one
    for(int i=0; i<k; i++) {

        // * Distance of obstacle from queen on y-axis
        y = obstacles[i][0] - r_q;

        // * Distance of obstacle from queen on x-axis
        x = obstacles[i][1] - c_q;

        // * If obstacle lies on x-axis on which queen is present
        if(y==0) {

            /*
            *   If obstacle lies to the left of queen,
            *   update the distance, queen can travel in left direction
            */
            if(x<0) {
                distance[0] = min(-(x+1), distance[0]);
            }

            /*
            *   If obstacle lies to the right of queen,
            *   update the distance, queen can travel in right direction
            */
            else {
                distance[2] = min(x-1, distance[2]);
            }
        }

        // * If obstacle lies on y-axis on which queen is present
        else if(x==0) {

            /*
            *   If obstacle lies to the bottom of queen,
            *   update the distance, queen can travel in bottom direction
            */
            if(y<0) {
                distance[3] = min(-(y+1), distance[3]);
            }

            /*
            *   If obstacle lies to the top of queen,
            *   update the distance, queen can travel in top direction
            */
            else {
                distance[1] = min(y-1, distance[1]);
            }
        }

        /*
        *   If obstacle is not present on the same x-axis or y-axis
        *   where the queen is present
        */
        else {

            /*
            *   Calculating the slope between the obstacle co-ordinates and queen co-ordinates
            *   to find out, if the obstacle lies in top-left, top-right,
            *   bottom-left or bottom-right direction
            */
            m = (float) y/x;

            /*
            *   If slope is 1.0, that means, obstacle is present to the
            *   top-right or to the bottom-left of the queen
            */
            if(m==1.0) {

                /*
                *   If obstacle is present to the top-right of the queen
                *   update the distance, queen can travel in top-right direction
                */
                if(x>0) {
                    distance[5] = min(x-1, distance[5]);
                }

                /*
                *   If obstacle is present to the bottom-left of the queen
                *   update the distance, queen can travel in bottom-left direction
                */
                else {
                    distance[7] = min(-(x+1), distance[7]);
                }
            }

            /*
            *   If slope is -1.0, that means, obstacle is present to the
            *   top-left or to the bottom-right of the queen
            */
            else if(m==-1.0) {

                /*
                *   If obstacle is present to the top-left of the queen
                *   update the distance, queen can travel in top-left direction
                */
                if(x<0) {
                    distance[4] = min(y-1, distance[4]);
                }

                /*
                *   If obstacle is present to the bottom-right of the queen
                *   update the distance, queen can travel in bottom-right direction
                */
                else {
                    distance[6] = min(x-1, distance[6]);
                }
            }
        }
    }

    /*
    *   Calculating the total number of squares the queen can travel
    *   by adding the distances it can travel in all directions
    */
    for(int i=0; i<8; i++) {
        numberOfSquares += distance[i];
    }

    // * Returning the total number of squares queen can travel
    return numberOfSquares;
}