/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Taum and B'day problem
*   Problem Link:- https://www.hackerrank.com/challenges/taum-and-bday/problem
*/
long taumBday(int b, int w, int bc, int wc, int z) {

    /*
    *   Calculating minimum of black cost and (white cost + conversion cost)
    *   per gift and multiplying it by total number of black gifts to find
    *   the total cost for black gifts. Similarly, calculating the minimum of
    *   white cost and (black cost + conversion cost) per gift and multiplying it
    *   by total number of white gifts to find the total cost for white gifts.
    *   Adding both black gifts cost and white gifts cost and returning the sum.
    *   Also, converting both the inputs to min() function into long
    *   for easy comparison as sum of two integers may not be covered in integer range
    */
    return b*min((long)bc, (long)wc+z) + w*min((long)wc, (long)bc+z);
}