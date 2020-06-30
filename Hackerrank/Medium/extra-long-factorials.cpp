/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Extra Long Factorials problem
*   Problem Link:- https://www.hackerrank.com/challenges/extra-long-factorials/problem
*/

/*
*   This method is used to multiply the number with the existing
*   array and return the resultant array size
*/
int multiply(int number, int resultArray[], int resultArraySize) {

    // * Initializing variables
    int carry = 0, mulRes;

    /*
    *   Calculating the result array by multiplying the
    *   existing array with new number
    */
    for(int i=0; i<resultArraySize; i++) {
        mulRes = number * resultArray[i] + carry;
        resultArray[i] = mulRes%10;
        carry = mulRes / 10;
    }

    /*
    *   Updating the result array
    *   with new value in carry
    */
    while(carry) {
        resultArray[resultArraySize++] = carry%10;
        carry = carry / 10;
    }

    // * Returning the updated result array size
    return resultArraySize;
}

void extraLongFactorials(int n) {

    // * Initializing variables
    int resultArray[200], resultArraySize = 1;
    resultArray[0] = 1;

    /*
    *   For each number in the factorial multiplication,
    *   multiply it with the result array and update
    *   the result array size variable
    */
    while(n) {
        resultArraySize = multiply(n--, resultArray, resultArraySize);
    }

    // * Displaying the result array in reverse order
    for(int i=resultArraySize-1; i>=0; i--) {
        cout<<resultArray[i];
    }
}