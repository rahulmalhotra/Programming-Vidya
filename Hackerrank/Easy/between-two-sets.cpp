/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Between Two Sets Problem
*   Problem Link:- https://www.hackerrank.com/challenges/between-two-sets/problem
*/

/*
*   This method is used to return the GCD of two numbers
*/
int gcd(int a,int b) {
    return b==0 ? a : gcd(b,a%b);
}

/*
*   This method is used to return the LCM of two numbers
*/
int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int getTotalX(vector<int> a, vector<int> b) {

    /*
    *   We need to calculate the LCM of all numbers in array A
    *   and GCD of all numbers in array B
    *   Initializing LCM by 1, GCD by first element of array B and count by 0
    */
    int lcmA=1, gcdB=b[0], count=0;

    /*
    *   Calculating LCM of all elements of array A
    */
    for(int i=0; i<a.size(); i++) {
        lcmA = lcm(lcmA, a[i]);
    }

    /*
    *   Calculating GCD of all elements of array B
    */
    for(int i=1; i<b.size(); i++) {
        gcdB = gcd(gcdB, b[i]);
    }

    /*
    *   All the multiples of LCM of array A that evenly divide
    *   GCD of array B, are the numbers that can be evenly divided by each element
    *   of array A and can evenly divide all the elements of array B. Therefore,
    *   all those numbers should be counted
    */
    for(int i=lcmA; i<=gcdB; i+=lcmA) {
        if(gcdB%i==0) {
            count++;
        }
    }

    // * Returning the count
    return count;
}