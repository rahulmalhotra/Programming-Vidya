/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Plus Minus problem
*   Problem Link:- https://www.hackerrank.com/challenges/plus-minus/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {

    // * Initializing variables
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;
    int totalCount = 0;

    // * Iterating through the vector
    for(int a : arr) {

        // * If the current integer is positive, increase the positive count by 1
        if(a>0) {
            positiveCount++;
        }

        // * Otherwise, if the current integer is negative, increase the negative count by 1
        else if(a<0) {
            negativeCount++;
        }

        // * Otherwise, if the current integer is zero, increase the zero count by 1
        else {
            zeroCount++;
        }

        // * Increase the total count by 1
        totalCount++;
    }

    /*
    *   Displaying the decimal value of positive, negative and
    *   zero count fraction upto 6 decimal places
    */
    printf("%.6f", (float) positiveCount/totalCount);
    cout<<endl;
    printf("%.6f", (float) negativeCount/totalCount);
    cout<<endl;
    printf("%.6f", (float) zeroCount/totalCount);
}

int main()
{
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

    plusMinus(arr);

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
