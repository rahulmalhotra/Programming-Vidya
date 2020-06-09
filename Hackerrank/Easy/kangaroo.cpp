/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Kangaroo Problem
*   Problem Link:- https://www.hackerrank.com/challenges/kangaroo/problem
*/
string kangaroo(int x1, int v1, int x2, int v2) {

    int divident = x2-x1;
    int divisor = v1-v2;

    /*
    *   If both divident and divisors are less than 0
    *   or, both are greater than 0.
    *   Also, if remainder of this division is 0.
    *   Both Kangaroo's will meet after divident/divisor
    *   number of steps, return YES
    */
    if(
        (
            (divident<0 && divisor<0) ||
            (divident>0 && divisor>0)
        ) &&
        (
            (divident%divisor) == 0
        )
    ) {
        return "YES";
    }

    // * If above is not true, return NO
    return "NO";
}