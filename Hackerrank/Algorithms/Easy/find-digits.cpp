/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Find Digits problem
*   Problem Link:- https://www.hackerrank.com/challenges/find-digits/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {

    // * Initializing variables
    int numberOfDivisors = 0, remainder = 0, number = n;

    // * Iterating while number is greater than 0
    while(number>0) {

        /*
        *   Finding the remainder when number is divided by 10
        *   i.e. the last digit of the number
        */
        remainder = number%10;

        /*
        *   If remainder is not zero and
        *   the number n is divisible by remainder,
        *   increment the number of divisors by 1
        */
        if(remainder!=0 && n%remainder==0) {
            numberOfDivisors++;
        }

        // * Dividing the number by 10 i.e. removing the last digit from number
        number = number/10;
    }

    // * Returning the number of divisors
    return numberOfDivisors;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
