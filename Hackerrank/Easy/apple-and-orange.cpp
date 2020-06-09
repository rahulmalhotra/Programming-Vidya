/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Apple and Orange Problem
*   Problem Link:- https://www.hackerrank.com/challenges/apple-and-orange/problem
*/
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {

    // * Initializing the number of apples and number of oranges to 0
    int numberOfApples = 0, numberOfOranges = 0;

    // * Counting the number of apples that fall on Sam's house
    for(int i=0; i<apples.size(); i++) {
        if(
            (apples[i] + a) >= s &&
            (apples[i] + a) <= t
        ) {
            numberOfApples++;
        }
    }

    // * Counting the number of oranges that fall on Sam's house
    for(int i=0; i<oranges.size(); i++) {
        if(
            (oranges[i] + b) >= s &&
            (oranges[i] + b) <= t
        ) {
            numberOfOranges++;
        }
    }

    // * Displaying the number of apples and oranges
    cout<<numberOfApples<<endl;
    cout<<numberOfOranges<<endl;
}