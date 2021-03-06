/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Largest Permutation problem
*   Problem Link:- https://www.hackerrank.com/challenges/largest-permutation/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the largestPermutation function below.
vector<int> largestPermutation(int k, vector<int> arr) {

    // * Initializing variables
    int length = arr.size(), numberOfSwaps = 0;

    /*
    *   Iterating the array elements one by one
    *   until the number of swaps are equal to k
    *   or we've reached the end of the array
    */
    for(int i=0; numberOfSwaps<k && i<length; i++, numberOfSwaps++) {

        /*
        *   If the current array element is at it's correct position,
        *   decrement the number of swaps by 1 and continue to the
        *   next element of the array
        */
        if(arr[i]==length-i) {
            numberOfSwaps--;
            continue;
        }

        /*
        *   Checking each element of the array
        *   starting from the next index to the
        *   length of the array
        */
        for(int j=i+1; j<length; j++) {

            /*
            *   If the element at index j should be at index i,
            *   swap it with the element at index i and break the loop
            */
            if(arr[j]==length-i) {
                swap(arr[j], arr[i]);
                break;
            }
        }
    }

    // * Returning the updated array
    return arr;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = largestPermutation(k, arr);

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
