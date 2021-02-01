/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Misère Nim problem
*   Problem Link:- https://www.hackerrank.com/challenges/misere-nim-1/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the misereNim function below.
string misereNim(vector<int> s) {

    // * Initializing variables
    int length = s.size(), sum = 0, xorAll = 0;

    /*
    *   If we have only one pile of stones
    *   and the number of stones are more than 1,
    *   first player will win, return "First".
    *   Otherwise, second player will win, return "Second"
    */
    if(length==1) {
        return s[0]>1 ? "First" : "Second";
    }

    /*
    *   Calculating the xor of all vector elements
    *   as well as the sum of all vector elements
    *   and storing the result in xorAll and
    *   sum variables respectively
    */
    for(int i=0; i<length; i++) {
        xorAll ^= s[i];
        sum += s[i];
    }

    /*
    *   If the sum of all vector elements is equal to the length
    *   of the vector, this means that we have one stone in each pile.
    *   If the number of piles are odd, second player will win, return "Second".
    *   Otherwise, first player will win, return "First"
    */
    if(sum==length) {
        return sum&1 ? "Second" : "First";
    }

    /*
    *   If xor of all elements in the vector is greater than 0,
    *   first player will win, return "First". Otherwise, second player
    *   will win, return "Second"
    */
    return xorAll > 0 ? "First" : "Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split_string(s_temp_temp);

        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            int s_item = stoi(s_temp[i]);

            s[i] = s_item;
        }

        string result = misereNim(s);

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
