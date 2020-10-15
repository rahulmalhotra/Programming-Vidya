/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank HackFest 2020 RGB Queries Problem
*   Problem Link:- https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/rbg/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'mixColors' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY colors
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<string> mixColors(vector<vector<int>> colors, vector<vector<int>> queries) {

    // * Initializing variables
    int cLength = colors.size();
    int qLength = queries.size();
    multimap<int, pair<int, int>> rmMap, bmMap, gmMap;
    vector<string> result;

    /*
    *   Iterating all colors and forming maps with
    *   red, blue and green color as keys
    */
    for(int i=0; i<cLength; i++) {
        rmMap.insert(make_pair(colors[i][0], make_pair(colors[i][1], colors[i][2])));
        bmMap.insert(make_pair(colors[i][1], make_pair(colors[i][0], colors[i][2])));
        gmMap.insert(make_pair(colors[i][2], make_pair(colors[i][0], colors[i][1])));
    }

    // * Considering each query one by one
    for(int i=0; i<qLength; i++) {

        // * Getting the red, blue and green color from the current query
        vector<int> query = queries[i];
        int red = query[0], blue = query[1], green = query[2];

        // * Marking hasRed, hasBlue and hasGreen variable to false initially for the current query
        bool hasRed = false, hasBlue = false, hasGreen = false;

        /*
        *   Getting the iterator to the lower bound and upper bound
        *   in the red multimap according to the current red color
        */
        multimap<int, pair<int, int>>::iterator itrS = rmMap.lower_bound(red);
        multimap<int, pair<int, int>>::iterator itrE = rmMap.upper_bound(red);

        /*
        *   If lower bound is equal to upper bound,
        *   red color of the current query is not present in the given colors.
        *   Add "NO" to the result and continue to the next query
        */
        if(itrS==itrE) {
            result.push_back("NO");
            continue;
        }

        /*
        *   If all the available colors have same amount of red color,
        *   mark hasRed as true
        */
        if(itrS == rmMap.begin() && itrE == rmMap.end()) {
            hasRed = true;
        }

        /*
        *   Otherwise, iterate the red multimap from the lower bound to the upper bound
        *   and check if the amount of blue and green in any color is less than or equal
        *   to the blue and green color of the current query. If that's true,
        *   mark hasRed as true and break the loop
        */
        else {
            for(multimap<int, pair<int, int>>::iterator itr = itrS; itr!=itrE; itr++) {
                pair<int, int> cp = (*itr).second;
                if(cp.first<=blue && cp.second<=green) {
                    hasRed = true;
                    break;
                }
            }
        }

        /*
        *   Getting the iterator to the lower bound and upper bound
        *   in the blue multimap according to the current blue color
        */
        multimap<int, pair<int, int>>::iterator itbS = bmMap.lower_bound(blue);
        multimap<int, pair<int, int>>::iterator itbE = bmMap.upper_bound(blue);

        /*
        *   If lower bound is equal to upper bound,
        *   blue color of the current query is not present in the given colors.
        *   Add "NO" to the result and continue to the next query
        */
        if(itbS==itbE) {
            result.push_back("NO");
            continue;
        }

        /*
        *   If all the available colors have same amount of blue color,
        *   mark hasBlue as true
        */
        if(itbS == bmMap.begin() && itbE == bmMap.end()) {
            hasBlue = true;
        }

        /*
        *   Otherwise, iterate the blue multimap from the lower bound to the upper bound
        *   and check if the amount of red and green in any color is less than or equal
        *   to the red and green color of the current query. If that's true,
        *   mark hasBlue as true and break the loop
        */
        else {
            for(multimap<int, pair<int, int>>::iterator itr = itbS; itr!=itbE; itr++) {
                pair<int, int> cp = (*itr).second;
                if(cp.first<=red && cp.second<=green) {
                    hasBlue = true;
                    break;
                }
            }
        }

        /*
        *   Getting the iterator to the lower bound and upper bound
        *   in the green multimap according to the current green color
        */
        multimap<int, pair<int, int>>::iterator itgS = gmMap.lower_bound(green);
        multimap<int, pair<int, int>>::iterator itgE = gmMap.upper_bound(green);

        /*
        *   If lower bound is equal to upper bound,
        *   green color of the current query is not present in the given colors.
        *   Add "NO" to the result and continue to the next query
        */
        if(itgS==itgE) {
            result.push_back("NO");
            continue;
        }

        /*
        *   If all the available colors have same amount of green color,
        *   mark hasGreen as true
        */
        if(itgS == gmMap.begin() && itgE == gmMap.end()) {
            hasGreen = true;
        }

        /*
        *   Otherwise, iterate the green multimap from the lower bound to the upper bound
        *   and check if the amount of red and blue in any color is less than or equal
        *   to the red and blue color of the current query. If that's true,
        *   mark hasGreen as true and break the loop
        */
        else {
            for(multimap<int, pair<int, int>>::iterator itr = itgS; itr!=itgE; itr++) {
                pair<int, int> cp = (*itr).second;
                if(cp.first<=red && cp.second<=blue) {
                    hasGreen = true;
                    break;
                }
            }
        }

        /*
        *   If red, blue, green colors of the current query
        *   are present in the colors and those colors can be
        *   combined to form the color provided in the query,
        *   add "YES" to result
        */
        if(hasRed && hasBlue && hasGreen) {
            result.push_back("YES");
        }

        // * Otherwise, add "NO" to result
        else {
            result.push_back("NO");
        }
    }

    // * Return the result
    return result;
}

// * Main function and other code given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> colors(n);

    for (int i = 0; i < n; i++) {
        colors[i].resize(3);

        string colors_row_temp_temp;
        getline(cin, colors_row_temp_temp);

        vector<string> colors_row_temp = split(rtrim(colors_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int colors_row_item = stoi(colors_row_temp[j]);

            colors[i][j] = colors_row_item;
        }
    }

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

    vector<string> result = mixColors(colors, queries);

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