/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Drawing Book Problem
*   Problem Link:- https://www.hackerrank.com/challenges/drawing-book/problem
*/
/*
*   Total number of steps needed to reach
*   the page p from start of book = p/2
*   Total number of steps needed to reach
*   the page p from end of book = n/2 - p/2
*/
int pageCount(int n, int p) {
    return min(p/2, n/2-p/2);
}