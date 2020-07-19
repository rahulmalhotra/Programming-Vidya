/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Jesse and Cookies Problem
*   Problem Link:- https://www.hackerrank.com/challenges/jesse-and-cookies/problem
*/
int cookies(int k, vector<int> A) {

    // * Initializing Variables
    priority_queue<int, vector<int>, greater<int>> pq;
    int length = A.size(), firstCookie, secondCookie, numberOfOperations = 0;

    // * Forming the min-heap using priority queue
    for(int i=0; i<length; i++) {
        pq.push(A[i]);
    }

    // * Getting the sweetness of first cookie i.e. top element from min-heap
    firstCookie = pq.top();

    /*
    *   We need to pop the first two cookies of min-heap and push the calculated
    *   sweetness of combined cookie until the first cookie has a sweetness less than k
    */
    while(firstCookie<k) {

        // * Removing the first cookie
        pq.pop();

        /*
        *   If queue is empty, this means that we have only one cookie
        *   whose sweetness is less than k. As it cannot be combined with any other cookie,
        *   break the loop
        */
        if(pq.empty()) {
            break;
        }

        // * Getting the sweetness of second cookie
        secondCookie = pq.top();

        // * Removing the second cookie
        pq.pop();

        // * Push the calculated sweetness by combining first two cookies in priority queue
        pq.push(firstCookie + 2*secondCookie);

        // * Getting the sweetness of first cookie which is just pushed to check before next iteration
        firstCookie = pq.top();

        // * Incrementing the number of operations by 1
        numberOfOperations++;
    }

    // * If queue is empty, return -1
    if(pq.empty()) {
        return -1;
    }

    // * Otherwise, return the numberOfOperations
    else {
        return numberOfOperations;
    }
}