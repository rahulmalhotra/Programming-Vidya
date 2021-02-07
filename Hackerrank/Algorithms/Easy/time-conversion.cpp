/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Time Conversion problem
*   Problem Link:- https://www.hackerrank.com/challenges/time-conversion/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {

    // * Initializing variables
    string ampm = s.substr(8,2), time = s.substr(0,2);
    int hour = stoi(time);

    // * If the time is in PM and hour < 12, add 12 to hour
    if(ampm.compare("PM")==0 && hour<12) {
        hour += 12;
        time = to_string(hour);
    }

    // * If the time is in PM and hour is equal to 12, make hour as 00
    else if(ampm.compare("AM")==0 && hour==12) {
        time = "00";
    }

    // * Append the minutes and seconds to the time
    time.append(s.substr(2,6));

    // * Return the time in military format in the response
    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
