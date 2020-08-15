/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef VOTERS Problem
*   Problem Link:- https://www.codechef.com/problems/VOTERS
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <stdio.h>
#include <set>
#include <unordered_map>
using namespace std;

int main() {

    /*
    *   Used to take input from input.txt
    *   and write output to output.txt
    */
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // * Declaring the variables
    int n1, n2, n3, element;
    unordered_map<int, int> freqMap;
    set<int> s;

    // * Accepting the size of voter lists
    cin>>n1>>n2>>n3;

    /*
    *   Accepting the voter ids in first list
    *   and forming the frequency map
    */
    for(int i=0; i<n1; i++) {
        cin>>element;
        freqMap[element]++;
    }

    /*
    *   Accepting the voter ids in the second list
    *   and forming the frequency map.
    *   Adding voter id to set if it's frequency > 1
    */
    for(int i=0; i<n2; i++) {
        cin>>element;
        freqMap[element]++;
        if(freqMap[element]>1) {
            s.insert(element);
        }
    }

    /*
    *   Accepting the voter ids in the third list
    *   and forming the frequency map.
    *   Adding voter id to set if it's frequency > 1
    */
    for(int i=0; i<n3; i++) {
        cin>>element;
        freqMap[element]++;
        if(freqMap[element]>1) {
            s.insert(element);
        }
    }

    // * Displaying the size of the final voters list
    cout<<s.size()<<endl;

    // * Displaying the final list of voters
    for(set<int>::iterator i=s.begin(); i!=s.end(); ++i) {
        cout<<*i<<endl;
    }
}