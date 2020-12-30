/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Array Manipulation problem
*   Problem Link:- https://www.hackerrank.com/challenges/crush/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {

    // * Initializing variables
    vector<long> arr(n+1, 0);
    int qLength = queries.size();
    long maximum = 0, sum = 0;

    /*
    *   Checking all queries one by one,
    *   adding each value to the starting index of the array
    *   and subtracting each value from the ending index of the array
    */
    for(int i=0; i<qLength; i++) {
        arr[queries[i][0]-1] += queries[i][2];
        arr[queries[i][1]] -= queries[i][2];
    }

    /*
    *   Calculating the prefix sum at each arr
    *   index one by one and finding the maximum
    *   prefix sum
    */
    for(int j=0; j<n; j++) {
        sum += arr[j];
        maximum = max(maximum, sum);
    }

    /*
    *   Returning the maximum value of the array
    *   if it's updated as given in the problem statement
    */
    return maximum;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
