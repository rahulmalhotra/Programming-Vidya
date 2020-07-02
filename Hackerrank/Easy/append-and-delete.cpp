/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Append and Delete problem
*   Problem Link:- https://www.hackerrank.com/challenges/append-and-delete/problem
*/
string appendAndDelete(string s, string t, int k) {

    // * Initializing variables
    int slen = s.length();
    int tlen = t.length();
    int totalMovesRequired = 0, i;

    // * Calculating total moves required to convert s to t
    for(i=0; i<slen && i<tlen; i++) {
        if(s[i] != t[i]) {
            break;
        }
    }
    totalMovesRequired = slen+tlen - 2*i;

    /*
    *   If total moves required are less than
    *   or equal to the given moves
    */
    if(totalMovesRequired<=k) {

        /*
        *   If one of the totalMovesRequired or
        *   given moves (k) is odd and other is even
        */
        if((totalMovesRequired+k)&1) {

            /*
            *   If string 's' can be fully deleted,
            *   return "Yes"
            */
            if(k>(slen+tlen)) {
                return "Yes";
            }

            // * Otherwise return "No"
            return "No";
        }

        /*
        *   If both totalMovesRequired and given moves (k)
        *   are odd, or both are even, return "Yes"
        */
        return "Yes";
    } else {
        /*
        *   If total moves required is
        *   more than the given moves (k),
        *   return "No"
        */
        return "No";
    }
}