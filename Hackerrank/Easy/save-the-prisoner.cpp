/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Save the Prisoner problem
*   Problem Link:- https://www.hackerrank.com/challenges/save-the-prisoner/problem
*/
int saveThePrisoner(int n, int m, int s) {

    /*
    *   Let's consider we're moving from index 0,
    *   so starting from beginning after distributing m sweets,
    *   we'll be at m-1 index. But we need to start from index s
    *   Therefore, it'll be m+s-1. Also, we need to consider 's'
    *   as well in the total count. So, we can get the final
    *   index by subtracting -1, therefore it'll be m+s-2.
    *   Now, we also need to limit the output to range n,
    *   as n is the total number of people, so,
    *   it'll be (m+s-2)%n. At the end, we'll be considering
    *   the count from 1, whereas, by doing a modulus by n
    *   we can get values in range 0 to n-1.
    *   Therefore, the final answer is (m+s-2)%n+1
    */
    return (m+s-2)%n+1;
}