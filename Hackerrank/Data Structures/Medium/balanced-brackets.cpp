/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Balanced Brackets problem
*   Problem Link:- https://www.hackerrank.com/challenges/balanced-brackets/problem
*/
string isBalanced(string s) {

    // * Initializing variables
    stack<char> bracketsStack;
    int length = s.size(), i;

    // * Checking each character of the string one by one
    for(i=0; i<length; i++) {

        /*
        *   If the current character is an opening bracket,
        *   push it into the stack
        */
        if(
            s[i]=='{' ||
            s[i]=='(' ||
            s[i]=='['
        ) {
            bracketsStack.push(s[i]);
        }

        /*
        *   If the current character is not an opening bracket,
        *   and the stack is empty, break the loop as we can't push
        *   the closing bracket into the stack if we don't have the
        *   corresponding opening bracket first
        */
        else if(
            bracketsStack.empty()
        ) {
            break;
        }

        /*
        *   If the current character is an closing bracket,
        *   and we have the related opening bracket at the stack top,
        *   pop the stack
        */
        else if(
            bracketsStack.top() == '{' &&
            s[i] == '}'
        ) {
            bracketsStack.pop();
        }
        else if(
            bracketsStack.top() == '(' &&
            s[i] == ')'
        ) {
            bracketsStack.pop();
        }
        else if(
            bracketsStack.top() == '[' &&
            s[i] == ']'
        ) {
            bracketsStack.pop();
        }

        /*
        *   Otherwise, break the loop as we don't have the corresponding
        *   opening bracket at the top of the stack
        *   according to the closing bracket
        */
        else {
            break;
        }
    }

    /*
    *   If the stack is empty and we have iterated the whole string,
    *   this means that the brackets are balanced, return "YES"
    */
    if(
        i == length &&
        bracketsStack.empty()
    ) {
        return "YES";
    }

    /*
    *   Otherwise, the brackets are not balanced, return "NO"
    */
    else {
        return "NO";
    }
}