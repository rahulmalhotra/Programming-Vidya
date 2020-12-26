/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Dynamic Array problem
*   Problem Link:- https://www.hackerrank.com/challenges/dynamic-array/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> dynamicArray(int n, vector<vector<int>> queries) {

    // * Initializing variables
    vector<int> result;
    vector<vector<int>> seqList;
    int length = queries.size(), index, lastAnswer = 0;

    // * Reserving n empty sequences
    seqList.reserve(n);

    /*
    *   Performing query operations
    *   on the list of sequences one by one
    *   and pushing the results to the result vector
    */
    for(int i=0; i<length; i++) {
        index = (queries[i][1]^lastAnswer)%n;
        if(queries[i][0]==1) {
            seqList[index].push_back(queries[i][2]);
        } else {
            lastAnswer = seqList[index][queries[i][2]%seqList[index].size()];
            result.push_back(lastAnswer);
        }
    }

    // * Returning the result vector
    return result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = dynamicArray(n, queries);

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
