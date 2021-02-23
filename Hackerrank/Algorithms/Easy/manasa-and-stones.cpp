/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Manasa and Stones problem
*   Problem Link:- https://www.hackerrank.com/challenges/manasa-and-stones/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {

    // * Initializing result vector
    vector<int> result;

    // * If both the values a and b are same, return (n-1) * a
    if(a==b) {
        result.push_back((n-1)*a);
    }

    // * Otherwise
    else {

        // * Store the bigger value in a
        if(a<b) {
            swap(a,b);
        }

        // * Calculate and push the possible values of last stones in result vector
        for(int i=0; i<n; i++) {
            result.push_back(i*a + (n-i-1)*b);
        }
    }

    // * Returning the result vector
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
