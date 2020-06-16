/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Bon Appetit Problem
*   Problem Link:- https://www.hackerrank.com/challenges/bon-appetit/problem
*/
void bonAppetit(vector<int> bill, int k, int b) {

    // * Initializing Variables
    int totalBillAmount = 0, amountAnnaShouldPay = 0;

    // * Calculating total bill amount
    for(int i=0; i<bill.size(); i++) {
        totalBillAmount += bill[i];
    }

    /*
    *   Calculating the amount Anna should pay,
    *   it will be half of the amount for dishes Anna had
    */
    amountAnnaShouldPay = (totalBillAmount - bill[k]) / 2;

    /*
    *   If total amount anna should pay is equal to the
    *   amount anna paid, display:- Bon Appetit
    *   Otherwise, display the refund Brian should return to Anna
    *   and the refund should be :-
    *   total amount anna paid - total amount anna should pay
    */
    if(b == amountAnnaShouldPay) {
        cout<<"Bon Appetit";
    } else {
        cout<<b-amountAnnaShouldPay;
    }
}