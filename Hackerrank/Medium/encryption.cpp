/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Encryption problem
*   Problem Link:- https://www.hackerrank.com/challenges/encryption/problem
*/
string encryption(string s) {

    // * Initializing variables
    int length = s.size(), columns, i, j;
    string encryptedString;

    // * Calculating the square root, you can also use round(sqrt(n))
    for(i=1; i*i<=length; i++);
    i--;

    /*
    *   If it's a perfect square, rows and columns
    *   will be the same i.e. equal to the square root i
    */
    if(i*i==length) {
        columns = i;
    }

    /*
    *   Otherwise, number of rows of grid = i
    *   number of columns = number of rows + 1
    */
    else {
        columns = i+1;
    }


    /*
    *   Calculating the encrypted string by
    *   performing an iteration over the whole string again
    *   and again according to the number of columns.
    *   In each iteration, we'll add the number of columns
    *   to the iteration counter in order to skip other characters
    *   that are not required
    */
    for(i=0; i<columns; i++) {

        for(j=i; j<length; j+=columns) {
            encryptedString.append(1, s[j]);
        }

        // * Append a space to the resultant string after each iteration
        encryptedString.append(1, ' ');
    }

    // * Returning the encrypted string
    return encryptedString;
}