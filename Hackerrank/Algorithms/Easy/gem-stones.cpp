/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Gemstones problem
*   Problem Link:- https://www.hackerrank.com/challenges/gem-stones/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {

    // * Initializing variables
    int numberOfRocks = arr.size(), freq[26] = {0}, count = 0;

    // * Considering each rock one by one
    for(int i=0; i<numberOfRocks; i++) {

        // * Storing the number of minerals in the current rock
        int numberOfMinerals = arr[i].length();

        // * Checking each mineral of the current rock one by one
        for(int j=0; j<numberOfMinerals; j++) {

            /*
            *   If the frequency of the current mineral is
            *   equal to the current rock index,
            *   increase the frequency by 1
            */
            if(freq[arr[i][j] - 'a'] == i) {
                freq[arr[i][j] - 'a']++;
            }
        }
    }

    // * Checking the frequency of each mineral one by one
    for(int i=0; i<26; i++) {

        /*
        *   If the frequency of the current mineral is equal to
        *   the total number of rocks, increase the count by 1
        */
        if(freq[i] == numberOfRocks) {
            count++;
        }
    }

    // * Returning the count in the response
    return count;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
