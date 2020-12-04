/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Grid Challenge problem
*   Problem Link:- https://www.hackerrank.com/challenges/grid-challenge/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the gridChallenge function below.
string gridChallenge(vector<string> grid) {

    // * Initializing variables
    int length = grid.size(), stringLength = grid[0].length();

    // * Sorting the characters in every string of the grid
    for(int i=0; i<length; i++) {
        sort(grid[i].begin(), grid[i].end());
    }

    /*
    *   Starting from 2nd row, checking if each
    *   character of the string in current row
    *   is lexicographically greater than the
    *   character of the string in previous row
    *   at the same index
    */
    for(int i=1; i<length; i++) {
        for(int j=0; j<stringLength; j++) {

            /*
            *   If any character at index j in the current string
            *   is less than the character at index j in the previous string,
            *   return "NO"
            */
            if(grid[i][j] < grid[i-1][j]) {
                return "NO";
            }
        }
    }

    /*
    *   Return YES, as the rows and columns of the grid
    *   are in ascending alphabetical order
    */
    return "YES";
}

// * Main function as given by HackerRank
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

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
