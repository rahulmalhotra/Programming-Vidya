/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank 2D Array - DS problem
*   Problem Link:- https://www.hackerrank.com/challenges/2d-array/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    // * Initializing variables
    int maxSum = -100, sum = 0;

    /*
    *   Calculating the sum of each hourglass one by one
    *   and finding the maximum hourglass sum
    */
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            maxSum = max(sum, maxSum);
        }
    }

    // * Returning the maximum hourglass sum
    return maxSum;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
