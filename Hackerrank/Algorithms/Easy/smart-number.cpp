/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Smart Number problem
*   Problem Link:- https://www.hackerrank.com/challenges/smart-number/problem
*   Website:- www.programmingvidya.com
*   Code Updates:-
*   Updated num / val == 1 in if condition to num == val*val on line number 20
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_smart_number(int num) {
    int val = (int) sqrt(num);
    if(num == val*val)
        return true;
    return false;
}

int main() {

    int test_cases;
    cin >> test_cases;
    int num;
    for(int i = 0; i < test_cases; i++) {
        cin >> num;
        bool ans = is_smart_number(num);
        if(ans) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}