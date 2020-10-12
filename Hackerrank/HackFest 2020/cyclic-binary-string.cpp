/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank HackFest 2020 Cyclic Binary String Problem
*   Problem Link:- https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/cyclic-binary-string
*	Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'maximumPower' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int maximumPower(string s) {

    // * Calculating the length of the string
    int size = s.length();

    // * Initializing zeroes count and maximum zeroes count to 0
    int zeroesCount = 0, maxZeroesCount = 0;

    /*
    *   Traversing the string and calculating the maximum
    *   consecutive zeroes
    */
    for(int i=0; i<size; i++) {
        if(s[i]=='0') {
            zeroesCount++;
        } else {
            maxZeroesCount = max(maxZeroesCount, zeroesCount);
            zeroesCount = 0;
        }
    }

    /*
    *   Checking if the zeroes at the end of the string
    *   is more than the zeroes count and updating the maximum zeroes count
    */
    maxZeroesCount = max(maxZeroesCount, zeroesCount);

    /*
    *   Checking if the total number of zeroes
    *   combining the start and end of the string
    *   is more than the maximum zeroes count.
    *   Update the maximum zeroes count
    */
    for(int i=0; s[i]=='0'; i++) {
        zeroesCount++;
    }
    maxZeroesCount = max(maxZeroesCount, zeroesCount);

    /*
    *   If the maximum zeroes count is greater than or equal to size
    *   of the string or we can say that all the elements in the string are 0s,
    *   return -1
    */
    if(maxZeroesCount>=size) {
        return -1;
    }

    // * If all the elements in the string are 1, return 0
    else if(maxZeroesCount==0) {
        return 0;
    }

    // * Otherwise, return the maximum zeroes count
    return maxZeroesCount;
}

// * Main function code given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = maximumPower(s);

    fout << result << "\n";

    fout.close();

    return 0;
}