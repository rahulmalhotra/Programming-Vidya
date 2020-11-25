/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Find the Median problem
*   Problem Link:- https://www.hackerrank.com/challenges/find-the-median/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

/*
*   This function is used to find the index at which
*   the element is placed at it's correct position.
*/
int partition(vector<int> &arr, int start, int end) {

    // * Getting a random position based on start and end index
    int randomPosition = start + rand() % (end - start + 1);

    /*
    *   Swapping the element at end position of the array
    *   with the element at random position
    */
    swap(arr[randomPosition], arr[end]);

    /*
    *   Initializing pivot with the element at the end of the array
    *   and j with the start index
    */
    int pivot = arr[end], j = start;

    /*
    *   Finding the correct position of the pivot element i.e. j.
    *   The array element whose value is less than pivot will be placed at a position
    *   less than j and the array elment whose value is more than pivot, will be placed
    *   at a position more than j
    */
    for(int i=start; i<end; i++) {
        if(arr[i]<pivot) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    // * Replacing the array element at position j with the pivot element
    swap(arr[j], arr[end]);

    // * Returning the index j as the pivot element is now present at j
    return j;
}

// * This function is used to find the median of the elements in the array
int findMedianInArray(vector<int> arr, int start, int end, int mid) {

    // * Calculating the current sorted element index
    int sortedElementIndex = partition(arr, start, end);

    /*
    *   If the sorted element index is equal to mid,
    *   return the element at this position as it's the median
    */
    if(sortedElementIndex == mid) {
        return arr[sortedElementIndex];
    }

    /*
    *   Otherwise, if the sorted element index is less than mid,
    *   the median is present in the right subarray.
    *   Find median in that subarray and return it
    */
    else if(sortedElementIndex < mid) {
        return findMedianInArray(arr, sortedElementIndex + 1, end, mid);
    }

    /*
    *   Otherwise, if the sorted element index is more than mid,
    *   the median is present in the left subarray.
    *   Find median in that subarray and return it
    */
    else {
        return findMedianInArray(arr, start, sortedElementIndex - 1, mid);
    }
}

// Complete the findMedian function below.
int findMedian(vector<int> arr) {

    // * Calculating the length of the array
    int length = arr.size();

    // * Returning the median of the array
    return findMedianInArray(arr, 0, length-1, length/2);
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

    int result = findMedian(arr);

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
