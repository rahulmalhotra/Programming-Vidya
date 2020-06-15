/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Day of the Programmer Problem
*   Problem Link:- https://www.hackerrank.com/challenges/day-of-the-programmer/problem
*/

string dayOfProgrammer(int year) {

    // * If year is 1918, 256th day will be 26th of September 1918
    if(year==1918) {
        return "26.09.1918";
    } else if(year<1918) {
        /*
        *   If year is less than 1918, we have to follow julian calendar,
        *   that means if year is divisible by 4, it's a leap year.
        *   In case of leap year, the 256th day will be 12th of September
        *   otherwise, the 256th day will be 13th of September
        */
        if(year%4==0) {
            return "12.09." + to_string(year);
        } else {
            return "13.09." + to_string(year);
        }
    } else {
        /*
        *   Otherwise, we have to follow gregorian calendar,
        *   that means if year is divisible by 400, it's a leap year.
        *   Otherwise, if year is divisible by 4 and
        *   it's not divisible by 100, it's a leap year.
        *   In case of leap year, the 256th day will be 12th of September
        *   otherwise, the 256th day will be 13th of September
        */
       if(year%400==0) {
            return "12.09." + to_string(year);
        } else if(year%4==0 && year%100!=0) {
            return "12.09." + to_string(year);
        } else {
            return "13.09." + to_string(year);
        }
    }
}