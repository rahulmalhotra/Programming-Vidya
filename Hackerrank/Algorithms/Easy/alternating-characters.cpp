/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Alternating Characters problem
*   Problem Link:- https://www.hackerrank.com/challenges/alternating-characters/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    // * Initializing variables
    int length = s.length(), count = 0;

    // * Counting the minimum number of required deletions
    for(int i=1; i<length; i++) {
        if(s[i-1]==s[i]) {
            count++;
        }
    }

    // * Returning the count
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
