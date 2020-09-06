/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank AND xor OR Problem
*   Problem Link:- https://www.hackerrank.com/challenges/and-xor-or/problem
*   Note:- Resolve the expression using boolean arithmetic first, the result is given below:-
*          (((M1&M2)^(M1|M2))&(M1^M2)) = M1^M2
*/
int andXorOr(vector<int> a) {

    // * Initializing Variables
    int size = a.size(), maxSi = 0;
    stack<int> s;

    // * Iterating the input vector
    for(int i=0; i<size; i++) {

        // * While stack is not empty
        while(!s.empty()) {

            /*
            *   XOR the top element of stack with the current element,
            *   compare it with the current maximum calculated value
            *   and update the maximum calculated value
            */
            maxSi = max(a[i]^s.top(), maxSi);

            /*
            *   If the current element is less than element
            *   at the top of stack, pop the stack,
            *   as the element at the top of stack should not be used
            *   in calculating xor with upcoming array elements
            */
            if(a[i] < s.top()) {
                s.pop();
            }

            /*
            *   Otherwise, break the loop as we have a smaller element
            *   present in the stack which should be used for calculating xor
            *   with upcoming array elements
            */
            else {
                break;
            }
        }

        /*
        *   Push the current element into the stack
        *   as it should be used in calculating xor
        *   with upcoming array elements
        */
        s.push(a[i]);
    }

    // * Return the maximum calculated value
    return maxSi;
}