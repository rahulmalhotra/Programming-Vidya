/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Mars Exploration problem
*   Problem Link:- https://www.hackerrank.com/challenges/mars-exploration/problem
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {

    // * Initializing variables
    int length = s.length(), count = 0;

    // * Checking each character of the string one by one
    for(int i=0; i<length; i++) {

        // * Taking the modulus of current index by 3 and storing it in j
        int j = i%3;

        /*
        *   If the current character is the first or third character
        *   of the 3 letter substring i.e. at substring index 0 or 2
        *   and it is not equal to S, increase the count
        */
        if((j==0 || j==2) && (s[i]!='S')) {
            count++;
        }

        /*
        *   If the current character is the second character
        *   of the 3 letter substring i.e. at substring index 1
        *   and it is not equal to O, increase the count
        */
        else if((j==1) && (s[i]!='O')) {
            count++;
        }
    }

    // * Returning the count from the function
    return count;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}