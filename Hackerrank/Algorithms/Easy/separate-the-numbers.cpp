/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Separate the Numbers problem
*   Problem Link:- https://www.hackerrank.com/challenges/separate-the-numbers/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {

    /*
    *   If the string is starting from 0,
    *   this means that the string is not beautiful
    *   Display NO and return
    */
    if(s[0]=='0') {
        cout<<"NO"<<endl;
        return;
    }

    // * Calculating the length of the string
    int length = s.length();

    // * Looping i from 1 till length/2
    for(int i=1; i<=length/2; i++) {

        // * Initializing initialNumberString and result
        string initialNumberString = s.substr(0, i), result = initialNumberString;

        // * Getting the current number from the current number string
        long long int currentNumber = stoll(initialNumberString);

        // * Looping while the length of result is less than length of string
        while(result.length()<length) {

            /*
            *   Incrementing the current number by 1,
            *   converting it to string and appending it
            *   to the result string
            */
            result.append(to_string(++currentNumber));
        }

        /*
        *   If the final result string is equal
        *   to the original string s, the string is beautiful.
        *   Display YES with the initialNumberString
        *   and return
        */
        if(s.compare(result)==0) {
            cout<<"YES "<<initialNumberString<<endl;
            return;
        }
    }

    // * Display NO as the string is not beautiful and return
    cout<<"NO"<<endl;
    return;
}

// * Main function as given by HackerRank
int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}