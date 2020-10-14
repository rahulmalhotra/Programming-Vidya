/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank HackFest 2020 Strictly Increasing Sequence Problem
*   Problem Link:- https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/strictly-increasing-sequence/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whoIsTheWinner' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string whoIsTheWinner(vector<int> arr) {

    // * Initializing variables
    unordered_map<int, int> freqMap;
    int size = arr.size();
    bool check = false;

    // * Creating a frequency map with the array elements
    for(int i=1; i<size; i++) {
        freqMap[arr[i]]++;
    }

    // * Iterating the frequency map
    for(unordered_map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); it++) {

        /*
        *   If any element in the frequency map
        *   has a value greater than 1, mark check as true
        */
        if(it->second>1) {
            check = true;
        }
    }

    // * If check is true
    if(check) {

        /*
        *   If the total number of elements
        *   in the array are odd, return "First"
        */
        if(size&1) {
            return "First";
        }

        // * Otherwise, return "Second"
        else {
            return "Second";
        }
    }

    // * If check is false
    else {
        return "First";
    }
}

// * Main function and other code given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = whoIsTheWinner(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}