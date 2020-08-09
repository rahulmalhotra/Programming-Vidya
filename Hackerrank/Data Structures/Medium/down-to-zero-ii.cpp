/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Down to Zero II Problem
*   Problem Link:- https://www.hackerrank.com/challenges/down-to-zero-ii/problem
*/

/*
*   This method will return the minimum number of moves
*   required to reduce the value of N to 0
*/
int downToZero(int n) {

    // * Initializing a queue
    queue<pair<int,int> > q;

    // * Initially, pushing n to the queue with depth as 0
    q.push(make_pair(n, 0));

    // * Executing the loop while queue is not empty
    while (!q.empty())
    {
        // * Getting the current pair from queue
        pair<int, int> cp = q.front();

        // * Popping the current pair from queue
        q.pop();

        /*
        *   If the value of current pair is equal to 4,
        *   return current depth + 3
        */
        if(cp.first==4) {
            return cp.second + 3;
        }
        /*
        *   If the value of current pair is less than 4,
        *   return current depth + current value
        */
        else if(cp.first<4) {
            return cp.second + cp.first;
        }

        /*
        *   Case 1:
        *   Push the current value - 1 and
        *   the current depth + 1 to queue
        */
        q.push(make_pair(cp.first - 1, cp.second + 1));

        /*
        *   Case 2:
        *   Start the counter with square root of current value.
        *   While the square root is greater than or equal to 2,
        *   decrement the counter and check if the current value is divisible
        *   by the current value of counter. If it is, push the other factor
        *   (which is greater than value of counter) in the queue and
        *   increment the current depth by 1 for it's value
        */
        for(int i=sqrt(cp.first); i>=2; i--) {
            if(cp.first%i==0) {
                q.push(make_pair(cp.first/i, cp.second + 1));
            }
        }
    }

    return 0;
}