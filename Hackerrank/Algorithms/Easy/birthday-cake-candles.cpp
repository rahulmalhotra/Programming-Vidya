/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Birthday Cake Candles problem
*   Problem Link:- https://www.hackerrank.com/challenges/birthday-cake-candles/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {

    // * Initializing variables
    int tallestCandle = 0, tallestCandleCount = 0;

    // * Looping over the candles one by one
    for(int candle : candles) {

        /*
        *   If the current candle height is
        *   greater than the tallest candle,
        *   set the tallest candle to current candle
        *   and the tallest candle count to 1
        */
        if(candle>tallestCandle) {
            tallestCandle = candle;
            tallestCandleCount = 1;
        }

        /*
        *   If the current candle height is equal to the height
        *   of tallest candle, increment the tallest candle count by 1
        */
        else if(candle==tallestCandle) {
            tallestCandleCount++;
        }
    }

    // * Returning the tallest candle count in the response
    return tallestCandleCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string candles_count_temp;
    getline(cin, candles_count_temp);

    int candles_count = stoi(ltrim(rtrim(candles_count_temp)));

    string candles_temp_temp;
    getline(cin, candles_temp_temp);

    vector<string> candles_temp = split(rtrim(candles_temp_temp));

    vector<int> candles(candles_count);

    for (int i = 0; i < candles_count; i++) {
        int candles_item = stoi(candles_temp[i]);

        candles[i] = candles_item;
    }

    int result = birthdayCakeCandles(candles);

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
