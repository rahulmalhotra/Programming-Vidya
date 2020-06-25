/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Beautiful Days at the Movies problem
*   Problem Link:- https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
*/

// * This method is used to reverse a given integer
int reverse(int num) {

    // * Initializing variables
    int rev = 0, rem = 0;

    // * Iterating while number is not zero
    while(num!=0) {

        /*
        *   Calculating the remainder by dividing
        *   the number by 10. This will give us the last
        *   digit of the number
        */
        rem = num%10;

        /*
        *   Multiplying the current reverse number by 10
        *   and adding the remainder in it. This will set
        *   the current remainder as the last digit of reversed number
        */
        rev = rev*10 + rem;

        /*
        *   Updating the actual number by dividing it by 10
        */
        num = num/10;
    }

    // * Returning the reverse of original number
    return rev;
}

int beautifulDays(int i, int j, int k) {

    // * Initializing variables
    int numberOfBeautifulDays = 0;

    /*
    *   Iterating all days in the range.
    *   If the absolute difference between day's original
    *   number and it's reverse is evenly divisible by k,
    *   increment the value for number of beautiful days
    *   abs() is used to ignore '-' sign if the difference is negative
    */
    for(int count=i; count<=j; count++) {
        if(abs(count-reverse(count))%k==0) {
            numberOfBeautifulDays++;
        }
    }

    // * Returning the number of beautiful days
    return numberOfBeautifulDays;
}