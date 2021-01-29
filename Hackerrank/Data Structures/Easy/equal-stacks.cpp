/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Equal Stacks problem
*   Problem Link:- https://www.hackerrank.com/challenges/equal-stacks/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {

    // * Initializing variables
    int h1Height = 0, h2Height = 0, h3Height = 0;
    int h1Index = 0, h2Index = 0, h3Index = 0;

    // * Calculating the height of stack h1
    for(vector<int>::iterator it = h1.begin(); it!= h1.end(); it++) {
        h1Height += *it;
    }

    // * Calculating the height of stack h2
    for(vector<int>::iterator it = h2.begin(); it!= h2.end(); it++) {
        h2Height += *it;
    }

    // * Calculating the height of stack h3
    for(vector<int>::iterator it = h3.begin(); it!= h3.end(); it++) {
        h3Height += *it;
    }

    // * Looping while height of all stacks are not equal
    while(h1Height!=h2Height || h2Height!=h3Height) {

        // * If height of any of the stacks is 0, return 0
        if(h1Height==0 || h2Height==0 || h3Height==0 ) {
            return 0;
        }

        // * If height of stack 1 is highest, remove top cylinder from stack 1
        if(h1Height>=h2Height && h1Height>=h3Height) {
            h1Height -= h1[h1Index++];
        }

        // * Otherwise, if height of stack 2 is highest, remove top cylinder from stack 2
        else if(h2Height>=h1Height && h2Height>=h3Height) {
            h2Height -= h2[h2Index++];
        }

        // * Otherwise, if height of stack 3 is highest, remove top cylinder from stack 3
        else if(h3Height>=h1Height && h3Height>=h2Height) {
            h3Height -= h3[h3Index++];
        }
    }

    // * Returning the height of stack 1, as all 3 stacks are of equal height now
    return h1Height;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

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
