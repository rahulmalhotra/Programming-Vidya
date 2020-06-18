/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Electronics Shop Problem
*   Problem Link:- https://www.hackerrank.com/challenges/electronics-shop/problem
*/

/*
*   This method is used as a custom comparator
*   to sort vector in reverse order
*/
bool reverseSortComparator(int a, int b) {
    return a>b;
}

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {

    // * Initializing maximum money spent variable by -1
    int maxMoneySpent = -1;

    /*
    *   Sorting keyboard prices in descending order and
    *   drive prices in ascending order
    */
    sort(keyboards.begin(), keyboards.end(), reverseSortComparator);
    sort(drives.begin(), drives.end());

    // * Looping Keyboard prices and drive prices
    for(int i=0, j=0; i<keyboards.size(); i++) {
        for(; j<drives.size(); j++) {

            /*
            *   If the sum of prices of keyboard and drive is more than budget,
            *   break the loop, notice that the counter 'j' for drives is not
            *   re-initialized in order to reduce complexity a little bit
            */
            if((keyboards[i] + drives[j]) > b) {
                break;
            } else {

                /*
                *   If the keyboard and drive's price is under or equal to budget,
                *   update the maximum money spent if the total price
                *   is greater than maximum money spent till now
                */
                maxMoneySpent = max(maxMoneySpent, keyboards[i] + drives[j]);
            }
        }
    }

    // * Return maximum money spent
    return maxMoneySpent;
}