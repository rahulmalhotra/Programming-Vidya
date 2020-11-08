/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Insertion Sort - Part 2 problem
*   Problem Link:- https://www.hackerrank.com/challenges/insertionsort2/problem
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

// Complete the insertionSort2 function below.
void insertionSort2(int n, vector<int> arr) {

    // * Declaring the variables
    int i, j, current;

    /*
    *   Considering each element of the array one by one
    *   starting from index 1
    */
    for(i=1; i<n; i++) {

        /*
        *   Initializing the current variable with the
        *   current element of the array at index i
        *   and the variable j with the index value
        *   previous to the current index (i-1)
        */
        current = arr[i];
        j = i-1;

        /*
        *   Looping while the current element is less then
        *   the element of the array at index j and
        *   the index j is greater than or equal to 0
        */
        while(j>=0 && arr[j]>current) {

            /*
            *   Copying the current element of the array
            *   from index j to index j+1
            */
            arr[j+1] = arr[j];

            // * Decreasing the index j by 1
            j--;
        }

        // * Storing the current element at j+1 index
        arr[j+1] = current;

        // * Displaying the array
        display(arr, n);
    }
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

    insertionSort2(n, arr);

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