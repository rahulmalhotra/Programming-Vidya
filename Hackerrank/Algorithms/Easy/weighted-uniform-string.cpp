/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Weighted Uniform Strings problem
*   Problem Link:- https://www.hackerrank.com/challenges/weighted-uniform-string/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {

    // * Initializing variables
    vector<string> result;
    set<int> weights;
    int length = s.length(), freq[26]= {0}, qLength = queries.size();
    char prev = s[0];

    /*
    *   Iterating the string and checking each character
    *   of the string one by one
    */
    for(int i=0; i<length; i++) {

        /*
        *   If the current character is not equal to previous character,
        *   set the current character's frequency to 0
        */
        if(prev != s[i]) {
            freq[s[i] - 'a'] = 0;
        }

        // * Increment the frequency of current character by 1
        freq[s[i] - 'a']++;

        // * Set the current character as the previous character for next iteration
        prev = s[i];

        // * Insert the weight of current substring into set of weights
        weights.insert(freq[s[i] - 'a'] * (s[i] - 'a' + 1));
    }

    /*
    *   Iterating the queries array and checking each
    *   weight of the queries array one by one
    */
    for(int i=0; i<qLength; i++) {

        /*
        *   If the current query weight is present
        *   in the set of weights, add "Yes" to the result
        */
        if(weights.find(queries[i]) != weights.end()) {
            result.push_back("Yes");
        }

        // * Otherwise, add "No" to the result
        else {
            result.push_back("No");
        }
    }

    // * Returning the result vector
    return result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
