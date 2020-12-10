/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Jim and the Orders problem
*   Problem Link:- https://www.hackerrank.com/challenges/jim-and-the-orders/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {

    // * Initializing variables
    vector<int> result;
    multimap<int, int> orderTimeCustomerMap;

    /*
    *   Forming the orderTimeCustomerMap by keeping
    *   order serve time as key and customer number
    *   as value for each order
    */
    for(int i=0; i<ordersLength; i++) {
        orderTimeCustomerMap.insert(make_pair(orders[i][0] + orders[i][1], i+1));
    }

    // * Adding customer numbers in sorted order in the result vector
    for(multimap<int, int>::iterator it = orderTimeCustomerMap.begin(); it!=orderTimeCustomerMap.end(); it++) {
        result.push_back(it->second);
    }

    // * Returning the result vector
    return result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}