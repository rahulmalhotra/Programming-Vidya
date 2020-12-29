/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Sparse Arrays problem
*   Problem Link:- https://www.hackerrank.com/challenges/sparse-arrays/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    // * Initializing variables
    vector<int> result;
    unordered_map<string, int> freqMap;

    /*
    *   Creating a frequency map to store
    *   the frequency of each input string
    */
    for(vector<string>::iterator it = strings.begin(); it!=strings.end(); it++) {
        freqMap[*it]++;
    }

    /*
    *   Storing the frequency of each query string
    *   in the result vector
    */
    for(vector<string>::iterator it = queries.begin(); it!=queries.end(); it++) {
        result.push_back(freqMap[*it]);
    }

    // * Returning the result vector
    return result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
