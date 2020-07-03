/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Library Fine problem
*   Problem Link:- https://www.hackerrank.com/challenges/library-fine/problem
*/
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {

    // * If years are equal, we need to check for months
    if(y1==y2) {

        // * If months are equal, we need to check for dates
        if(m1==m2) {

            /*
            *   If due date is less than or equal to
            *   expected date, fine will be 0 as month
            *   and year are same
            */
            if(d1<=d2) {
                return 0;
            }

            /*
            *   Otherwise, fine will be 15 multiplied by
            *   difference between the dates
            */
            else {
                return 15*(d1-d2);
            }
        }

        /*
        *   If returned month is less than due month,
        *   fine will be 0 as year is same
        */
        else if(m1<m2) {
            return 0;
        }

        /*
        *   Otherwise, fine will be 500 multiplied by
        *   difference between the months
        */
        else {
            return 500*(m1-m2);
        }
    }

    /*
    *   If returned year is less than due year,
    *   fine will be 0
    */
    else if(y1<y2) {
        return 0;
    }

    // * Otherwise, fine is 10,000 fixed
    else {
        return 10000;
    }
}