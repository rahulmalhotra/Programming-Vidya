/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank The Bomberman Game problem
*   Problem Link:- https://www.hackerrank.com/challenges/bomber-man/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {

    // * After 1 second, bomberman does nothing
    if(n==1) {
        return grid;
    }

    /*
    *   Creating a grid to store position of bombs
    *   and initializing all the values
    *   in that grid to 0
    */
    int posGrid[200][200];
    for(int i=0; i<200; i++) {
        for(int j=0; j<200; j++) {
            posGrid[i][j] = 0;
        }
    }

    // * Initializing variables
    int numberOfRows = grid.size(), numberOfColumns = grid[0].length();

    /*
    *   Setting up the position grid with 1 at positions
    *   where bombs are placed initially and setting up
    *   the grid with bombs at all the positions
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            if(grid[i][j]==79) {
                posGrid[i][j] = 1;
            }
            grid[i][j] = 79;
        }
    }

    /*
    *   After 2 seconds or if the number of seconds
    *   are even, the grid will be full.
    *   Returning the grid with bombs
    *   at all the positions
    */
    if(n%2==0) {
        return grid;
    }

    /*
    *   After 3 seconds, the bombs placed initially
    *   will detonate, updating the grid
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            if(posGrid[i][j]==1) {
                grid[i][j] = '.';
                if(j-1>=0) {
                    grid[i][j-1] = '.';
                }
                if(i-1>=0) {
                    grid[i-1][j] = '.';
                }
                if(j+1<numberOfColumns) {
                    grid[i][j+1] = '.';
                }
                if(i+1<numberOfRows) {
                    grid[i+1][j] = '.';
                }
            }
        }
    }

    /*
    *   The grid now obtained will be repeated at second
    *   7, 11, 15, 19, 23....
    *   Therefore, returning this grid if the number of seconds
    *   when divided by 4 gives the remainder 3
    */
    if(n%4==3) {
        return grid;
    }

    /*
    *   Again forming the position grid
    *   by having a look at the positions
    *   where bombs are placed now. Also, updating
    *   the grid as it will look like after 4 seconds
    *   i.e. with bombs at all positions
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            posGrid[i][j] = 0;
            if(grid[i][j]==79) {
                posGrid[i][j] = 1;
            }
            grid[i][j] = 79;
        }
    }

    /*
    *   After 5 seconds, the bombs placed after 2 seconds
    *   will detonate, updating the grid
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            if(posGrid[i][j]==1) {
                grid[i][j] = '.';
                if(j-1>=0) {
                    grid[i][j-1] = '.';
                }
                if(i-1>=0) {
                    grid[i-1][j] = '.';
                }
                if(j+1<numberOfColumns) {
                    grid[i][j+1] = '.';
                }
                if(i+1<numberOfRows) {
                    grid[i+1][j] = '.';
                }
            }
        }
    }

    /*
    *   The grid now obtained will be repeated at second
    *   9, 13, 17, 21, 25....
    *   Therefore, returning this grid as the other possibilities
    *   are already considered above
    */
    return grid;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
