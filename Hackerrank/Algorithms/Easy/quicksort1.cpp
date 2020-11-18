/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Quicksort 1 - Partition problem
*   Problem Link:- https://www.hackerrank.com/challenges/quicksort1/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the quickSort function below.
vector<int> quickSort(vector<int> arr) {

    // * Initializing variables
    int pivot = arr[0], length = arr.size();

    /*
    *   Creating left, right and result vectors.
    *   Equal vector is not needed as all the elements are unique,
    *   so equal vector will only have one element which is the pivot
    */
    vector<int> left, right, result;

    // * Iterating all the elements in the array except the pivot
    for(int i=1; i<length; i++) {

        /*
        *   If the current element is less than pivot,
        *   push it to the left vector
        */
        if(arr[i]<pivot) {
            left.push_back(arr[i]);
        }

        /*
        *   Otherwise, if the current element is greater than pivot,
        *   push it to the right vector
        */
        else if(arr[i]>pivot) {
            right.push_back(arr[i]);
        }
    }

    // * Initializing an iterator to the beginning of result vector
    vector<int>::iterator it = result.begin();

    /*
    *   Inserting all the elements of the left
    *   vector at the beginning of result vector
    */
    result.insert(it, left.begin(), left.end());

    // * Inserting the pivot at the end of the result vector
    result.push_back(pivot);

    // * Setting the iterator to the end of result vector
    it = result.end();

    /*
    *   Inserting all the elements of the right
    *   vector at the end of result vector
    */
    result.insert(it, right.begin(), right.end());

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

    vector<int> result = quickSort(arr);

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
