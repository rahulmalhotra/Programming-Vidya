/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Closest Numbers problem
*   Problem Link:- https://www.hackerrank.com/challenges/closest-numbers/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {

    // * Sorting the array
    sort(arr.begin(), arr.end());

    // * Initializing variables
    int length = arr.size(), minDiff = arr[1] - arr[0], currentDiff;
    vector<int> result;

    // * Iterating the array elements starting from index 1
    for(int i=1; i<length; i++) {

        /*
        *   Calculating the difference between the current element
        *   and the previous element of the array
        */
        currentDiff = arr[i] - arr[i-1];

        // * If the current difference is less than the minimum difference
        if(currentDiff < minDiff) {

            // * Mark the current difference as the minimum difference
            minDiff = currentDiff;

            // * Clearing the result vector
            result.clear();

            // * Pushing the previous and current element of the array into the result vector
            result.push_back(arr[i-1]);
            result.push_back(arr[i]);
        }

        // * Otherwise, if the current difference is equal to the minimum difference
        else if(currentDiff == minDiff) {

            // * Pushing the previous and current element of the array into the result vector
            result.push_back(arr[i-1]);
            result.push_back(arr[i]);
        }
    }

    // * Returning the result vector
    return result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
