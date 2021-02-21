/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Chocolate Feast problem
*   Problem Link:- https://www.hackerrank.com/challenges/chocolate-feast/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the chocolateFeast function below.
int chocolateFeast(int n, int c, int m) {

    // * Initializing variables
    int numberOfWrappers = n/c;
    int numberOfChocolates = numberOfWrappers;
    int chocolatesToBuy = numberOfWrappers/m;

    // * Looping while bobby can buy more chocolates
    while(chocolatesToBuy) {

        // * Increment the number of chocolates by chocolates bought by bobby
        numberOfChocolates += chocolatesToBuy;

        /*
        *   Update the number of wrappers by the sum of
        *   the number of wrappers left after buying
        *   previous chocolates and the wrappers of chocolates
        *   just bought
        */
        numberOfWrappers = numberOfWrappers%m + chocolatesToBuy;

        // * Updating the chocolates that can be further bought by the available wrappers
        chocolatesToBuy = numberOfWrappers/m;
    }

    /*
    *   Returning the total number of chocolates
    *   Bobby can eat after taking full advantage of the promotion
    */
    return numberOfChocolates;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string ncm_temp;
        getline(cin, ncm_temp);

        vector<string> ncm = split_string(ncm_temp);

        int n = stoi(ncm[0]);

        int c = stoi(ncm[1]);

        int m = stoi(ncm[2]);

        int result = chocolateFeast(n, c, m);

        fout << result << "\n";
    }

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
