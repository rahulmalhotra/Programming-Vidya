/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Marc's Cakewalk problem
*   Problem Link:- https://www.hackerrank.com/challenges/marcs-cakewalk/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the marcsCakewalk function below.
long marcsCakewalk(vector<int> calorie) {

    // * Initializing variables, forming a max heap by using the calorie vector
    priority_queue<int, vector<int>> pq(calorie.begin(), calorie.end());
    long minimumMiles = 0, pivot = 1;

    /*
    *   While the max heap is not empty,
    *   picking each calorie one by one in decreasing order
    *   and calculating the minimum miles, marc must walk to
    *   maintain his weight
    */
    while(!pq.empty()) {
        minimumMiles += pivot * pq.top();
        pq.pop();
        pivot *= 2;
    }

    // * Returning the minimum miles
    return minimumMiles;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string calorie_temp_temp;
    getline(cin, calorie_temp_temp);

    vector<string> calorie_temp = split_string(calorie_temp_temp);

    vector<int> calorie(n);

    for (int i = 0; i < n; i++) {
        int calorie_item = stoi(calorie_temp[i]);

        calorie[i] = calorie_item;
    }

    long result = marcsCakewalk(calorie);

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
