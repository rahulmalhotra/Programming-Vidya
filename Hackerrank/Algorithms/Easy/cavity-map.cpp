/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Cavity Map problem
*   Problem Link:- https://www.hackerrank.com/challenges/cavity-map/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {

    // * Initializing variables
    int rows = grid.size();
    int columns = grid[0].size();

    // * Looping through the grid
    for(int i=1; i<rows-1; i++) {
        for(int j=1; j<columns-1; j++) {

            // * Storing the depth of top cell
            int top = grid[i][j-1] - '0';

            // * Storing the depth of bottom cell
            int bottom = grid[i][j+1] - '0';

            // * Storing the depth of left cell
            int left = grid[i-1][j] - '0';

            // * Storing the depth of right cell
            int right = grid[i+1][j] - '0';

            // * Storing the depth of current cell
            int current = grid[i][j] - '0';

            /*
            *   If the depth of current cell is greater then the depth
            *   of the cell on it's left, right, top and bottom, replace
            *   the value of current cell by X
            */
            if(current>left && current>right && current>top && current>bottom) {
                grid[i][j] = 'X';
            }
        }
    }

    // * Return the grid
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
