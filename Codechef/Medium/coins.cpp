/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef COINS Problem
*   Problem Link:- https://www.codechef.com/problems/COINS
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;

// * Declaring the amountMap variable
unordered_map<long long int, long long int> amountMap;

/*
*   This function will calculate and
*   return the maximum amount that we can get for the gold coin
*/
long long int getMaxAmount(long long int coin) {

    // * If coint is of value 0 or 1, return the same amount
    if(coin==0 || coin==1) {
        return coin;
    }

    // * Otherwise, if we've calculated the amount of coin before, return it
    else if(amountMap[coin]) {
        return amountMap[coin];
    }

    /*
    *   Otherwise, calculate the maximum amount that we can get in exchange
    *   for the coin and return it. Also, store that amount for future use
    */
    else {
        amountMap[coin] = max(getMaxAmount(coin/2) + getMaxAmount(coin/3) + getMaxAmount(coin/4) , coin);
        return amountMap[coin];
    }
}

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Initializing the variables
    long long int coin, amount;

    // * Accepting the coins
    while(cin>>coin) {

        /*
        *   Calculate the maximum amount of american dollars
        *   that we can get in exchange of this gold coin
        *   and display that
        */
        cout<<getMaxAmount(coin)<<endl;
    }
}