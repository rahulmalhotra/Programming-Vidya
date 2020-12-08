/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Priyanka and Toys problem
*   Problem Link:- https://www.hackerrank.com/challenges/priyanka-and-toys/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the toys function below.
int toys(vector<int> w) {

    // * Creating a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // * Adding all elements of the vector w to the min heap
    for(vector<int>::iterator it = w.begin(); it!=w.end(); it++) {
        pq.push(*it);
    }

    // * Initializing variables
    int start = pq.top(), numberOfContainers = 1;

    /*
    *   Removing the first element from the min heap as it is marked
    *   as the start element of first container
    */
    pq.pop();

    // * Looping while min heap is not empty
    while(!pq.empty()) {

        /*
        *   If the current element at the top
        *   of the min heap is greater than the
        *   start element of current container + 4
        */
        if(pq.top()>start+4) {

            /*
            *   Set the current element as the
            *   start element of next container
            */
            start = pq.top();

            // * Increment the number of containers by 1
            numberOfContainers++;
        }

        // * Remove the element from the min heap
        pq.pop();
    }

    // * Returning the number of containers
    return numberOfContainers;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string w_temp_temp;
    getline(cin, w_temp_temp);

    vector<string> w_temp = split_string(w_temp_temp);

    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        int w_item = stoi(w_temp[i]);

        w[i] = w_item;
    }

    int result = toys(w);

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
