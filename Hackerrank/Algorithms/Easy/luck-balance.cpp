/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Luck Balance problem
*   Problem Link:- https://www.hackerrank.com/challenges/luck-balance/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {

    // * Initializing variables
    priority_queue<int, vector<int>> pq;
    int length = contests.size(), maxLuck = 0;

    /*
    *   Storing the amount of luck of all
    *   the important contests in a max heap.
    *   Also, summing up the amount of luck for
    *   all the unimportant contests in maxLuck variable
    */
    for(int i=0; i<length; i++) {
        if(contests[i][1]) {
            pq.push(contests[i][0]);
        } else {
            maxLuck += contests[i][0];
        }
    }

    /*
    *   While max heap is not empty and
    *   we've not counted k important contests,
    *   add the luck for each important
    *   contests to the maxLuck variable
    */
    while(!pq.empty() && k--) {
        maxLuck += pq.top();
        pq.pop();
    }

    /*
    *   While max heap is not empty,
    *   subtract the luck of each imporant
    *   contest from the maxLuck variable
    */
    while(!pq.empty()) {
        maxLuck -= pq.top();
        pq.pop();
    }

    /*
    *   Returning the maximum amount of luck
    *   Lena can have after all the contests
    */
    return maxLuck;
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

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

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
