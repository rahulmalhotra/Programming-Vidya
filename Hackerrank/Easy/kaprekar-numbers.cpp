/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Modified Kaprekar Numbers problem
*   Problem Link:- https://www.hackerrank.com/challenges/kaprekar-numbers/problem
*/

bool isKaprekarNumber(int x) {

    // * Calculating the square of the number
    long long square = (long long) x*x;

    // * Converting the square to string
    string sqString = to_string(square);
    int size = sqString.size();

    // * Dividing the string into two halves
    string leftString = sqString.substr(0, size/2);
    string rightString = sqString.substr(size/2, size);

    // * Converting each string into integer
    int leftNum = leftString.empty() ? 0 : stoi(leftString);
    int rightNum = rightString.empty() ? 0 : stoi(rightString);

    /*
    *   If sum of both integers is equal to initial number,
    *   then the number is a kaprekar number, return true
    */
    if(leftNum + rightNum == x) {
        return true;
    }

    // * Number is not a kaprekar number, return false
    return false;
}

void kaprekarNumbers(int p, int q) {

    // * Initializing variables
    bool kaprekarNumberFound = false;

    // * Considering each number in the range one by one
    for(int i=p; i<=q; i++) {

        /*
        *   If the current number is a kaprekar number, print it
        *   and set kaprekarNumberFound to true
        */
        if(isKaprekarNumber(i)) {
            cout<<i<<" ";
            kaprekarNumberFound = true;
        }
    }

    // * If no kaprekar number found, print "INVALID RANGE"
    if(!kaprekarNumberFound) {
        cout<<"INVALID RANGE";
    }
}