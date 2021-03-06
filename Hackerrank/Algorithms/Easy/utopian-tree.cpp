/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Utopian Tree problem
*   Problem Link:- https://www.hackerrank.com/challenges/utopian-tree/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {

    // * Initializing height to 1
    int height = 1;

    /*
    *   Incrementing the height of the tree for each spring and
    *   summer season, considering the spring season when i is odd and
    *   the summer season when i is even
    */
    for(int i=1; i<=n; i++) {
        if(i&1) {
            height *= 2;
        } else {
            height++;
        }
    }

    // * Returning the height of the tree
    return height;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
