/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Fair Rations problem
*   Problem Link:- https://www.hackerrank.com/challenges/fair-rations/problem
*	Website:- www.programmingvidya.com
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);

// Complete the fairRations function below.
int fairRations(vector<int> B) {

    // * Initializing variables
    int bLength = B.size(), count = 0;

    /*
    *   Checking the number of loaves with each person
    *   one by one except the last person
    */
    for(int i=0; i<bLength-1; i++) {

        /*
        *   If the number of loaves with any person is odd,
        *   increase the number of loaves with him/her by one.
        *   Also, increase the number of loaves with the person
        *   to the right by 1. Increase the count by 2
        */
        if(B[i]&1) {
            B[i]++;
            B[i+1]++;
            count+=2;
        }
    }

    /*
    *   If the number of loaves with last person is odd,
    *   return -1
    */
    if(B[bLength-1] & 1) {
        return -1;
    }

    // * Returning the count
    return count;
}

// * Main function given by HackerRank (Modified by us to handle -1 return value and print "NO")
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split_string(B_temp_temp);

    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = fairRations(B);

    // * Modified main function here to handle -1 return value and print "NO"
    if(result==-1) {
        fout << "NO" <<"\n";
    } else {
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