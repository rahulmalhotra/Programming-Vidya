/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Insertion Sort - Part 1 problem
*   Problem Link:- https://www.hackerrank.com/challenges/insertionsort1/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// * This function is used to display the array
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Complete the insertionSort1 function below.
void insertionSort1(int n, vector<int> arr) {

    // * Initializing variables
    int last = arr[n-1], i = n-2;

    /*
    *   Looping while the last element is less then
    *   the current element of the array and
    *   the current index is greater than or equal to 0
    */
    while(i>=0 && arr[i]>last) {

        /*
        *   Copying the current element of the array
        *   from current index i to index i+1
        */
        arr[i+1] = arr[i];

        // * Displaying the array
        display(arr, n);

        // * Decreasing the index i by 1
        i--;
    }

    // * Storing the last element at i+1 index
    arr[i+1] = last;

    // * Displaying the final sorted array
    display(arr, n);
}

// * Main function as given by HackerRank
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

    insertionSort1(n, arr);

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