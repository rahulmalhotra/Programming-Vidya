/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank HackFest 2020 Game of Maximization Problem
*   Problem Link:- https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/stones-piles/problem
*	Website:- www.programmingvidya.com
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumStones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int maximumStones(vector<int> arr) {

    /*
    *   Calculating the array size and
    *   initializing odd sum and even sum variables to 0
    */
    int size = arr.size();
    int oddSum = 0, evenSum = 0;

    /*
    *   Adding the array elements at odd and even
    *   indexes starting from 1 to odd sum and even sum.
    */
    for(int i=1; i<=size; i++) {
        if(i&1) {
            oddSum += arr[i-1];
        } else {
            evenSum += arr[i-1];
        }
    }

    // * Returning [minimum of (odd sum or even sum)] * 2
    return min(oddSum, evenSum) * 2;
}

// * Main function and other code given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = maximumStones(arr);

    fout << result << "\n";

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
