/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Birthday Chocolate Problem
*   Problem Link:- https://www.hackerrank.com/challenges/the-birthday-bar/problem
*/
int birthday(vector<int> s, int d, int m) {

    // * Initializing the variables
    int length = s.size(), birthDate = 0, count=0, si=0;

    // * If number of months is more than total length of chocolate, return 0
    if(m>length) {
        return 0;
    }

    /*
    *   Calculate the initial birth date
    *   formed by adding m chocolate segments
    */
    for(int i=0; i<m; i++) {
        birthDate += s[i];
    }

    /*
    *   If the initial calculated birth date is equal to d,
    *   increment count by 1
    */
    if(birthDate==d) {
        count++;
    }

    /*
    *   Calculating the new birth dates formed by adding
    *   m chocolate segments one by one by incrementing the starting index
    *   si and also the ending index ei by 1. We're subtracting the value of starting
    *   index from birthDate and adding the value of ending index in the birthDate
    *   to form the birth date of next block of segments having a length m.
    *   If birthDate is equal to d, increment count by 1
    */
    for(int ei=m; ei<length; ei++, si++) {
        birthDate-=s[si];
        birthDate+=s[ei];
        if(birthDate==d) {
            count++;
        }
    }

    // * Return the count
    return count;
}
