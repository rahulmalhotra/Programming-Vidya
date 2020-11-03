/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Big Sorting problem
*   Problem Link:- https://www.hackerrank.com/challenges/big-sorting/problem
*	Website:- www.programmingvidya.com
*/
#include <bits/stdc++.h>
using namespace std;

// * Comparator function used in sorting the numeric strings
bool sortComparator(string a, string b) {

    // * Getting the length of string a and b
    int aLength = a.length();
    int bLength = b.length();

    /*
    *   If both the strings are of equal length,
    *   sort them lexicographically
    */
    if(aLength == bLength) {
        return a < b;
    }

    /*
    *   Otherwise, keep the short string
    *   before the long string in sorted order
    */
    return aLength < bLength;
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {

    /*
    *   Using the in-built sort function
    *   with our custom comparator to
    *   sort the numeric strings
    */
    sort(unsorted.begin(), unsorted.end(), sortComparator);

    // * Returning the sorted vector
    return unsorted;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}