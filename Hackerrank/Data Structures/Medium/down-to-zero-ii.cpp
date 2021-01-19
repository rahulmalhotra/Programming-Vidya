/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Down to Zero II Problem
*   Problem Link:- https://www.hackerrank.com/challenges/down-to-zero-ii/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the downToZero function below.
 */
int downToZero(int n) {

    // * Initializing variables
    queue<int> q;
    int dp[1000001] = {0};

    // * Pushing n to the queue
    q.push(n);

    // * Executing the loop while queue is not empty
    while (!q.empty())
    {
        // * Getting the current number
        int cn = q.front();

        // * Popping the current number from queue
        q.pop();

        /*
        *   If the current number is 0, break the loop
        *   as we don't need to scan the queue further
        */
        if(cn==0) {
            break;
        }

        /*
        *   Case 1:
        *   If the current number - 1, is not present in the queue,
        *   Push the current number - 1 to the queue and
        *   the number of moves + 1 to the dp array for the new value
        */
        if(dp[cn-1]==0) {
            q.push(cn-1);
            dp[cn-1] = dp[cn] + 1;
        }

        /*
        *   Case 2:
        *   Start the counter with square root of current number.
        *   While the square root is greater than or equal to 2,
        *   decrement the counter and check if the current number is divisible
        *   by the current value of counter. If it is, and the value after division
        *   is not already present in the queue, push the new value in the queue and
        *   add the number of moves + 1 to the dp array for the new value
        */
        for(int i=sqrt(cn); i>=2; i--) {
            if(cn%i==0 && dp[cn/i]==0) {
                q.push(cn/i);
                dp[cn/i] = dp[cn] + 1;
            }
        }
    }

    // * Return the number of moves to reduce n to 0
    return dp[0];
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
