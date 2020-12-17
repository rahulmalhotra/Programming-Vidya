/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Game of Stones problem
*   Problem Link:- https://www.hackerrank.com/challenges/game-of-stones-1/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the gameOfStones function below.
string gameOfStones(int n) {

    /*
    *   If n when divided by 7,
    *   gives remainder 0 or 1,
    *   Second player wins.
    *   Otherwise, First player wins.
    */
    if(n%7==0 || n%7==1) {
        return "Second";
    }
    return "First";
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

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}