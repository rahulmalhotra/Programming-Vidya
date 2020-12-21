/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank A Chessboard Game problem
*   Problem Link:- https://www.hackerrank.com/challenges/a-chessboard-game-1/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the chessboardGame function below.
string chessboardGame(int x, int y) {

    /*
    *   Getting the remainder by
    *   dividing x and y by 4 and
    *   storing that in x and y
    */
    x = x%4;
    y = y%4;

    /*
    *   If any of the remainder is 0 or 3,
    *   return First as first player is the winner
    */
    if(x==0 || x==3 || y==0 || y==3) {
        return "First";
    }

    /*
    *   Otherwise, return Second
    *   as second player is the winner
    */
    return "Second";
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        string result = chessboardGame(x, y);

        fout << result << "\n";
    }

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