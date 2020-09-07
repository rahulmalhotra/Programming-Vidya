/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Largest Rectangle Problem
*   Problem Link:- https://www.hackerrank.com/challenges/largest-rectangle/problem
*/
long largestRectangle(vector<int> h) {

    // * Adding 0 to the end of the vector i.e. a building with height 0
    h.push_back(0);

    // * Initializing the variables
    int size = h.size();
    stack<int> s;
    long maxArea = 0, currentArea;

    // * Adding 0 index to the stack initially
    s.push(0);

    // * Iterating elements from index 1
    for(int i=1; i<size; i++) {

        /*
        *   Iterating while the height of the current building
        *   is less than the height of the building at top of the stack.
        *   We're finding the area spanned by the building at the top of stack.
        */
        while(h[i]<h[s.top()]) {

            /*
            *   Finding the current area i.e. the area spanned
            *   by the building whose index is present at the
            *   top of stack. If after popping the topmost value,
            *   the stack is empty,
            *   area = building height * the current index
            */
            currentArea = h[s.top()];
            s.pop();
            if(s.empty()) {
                currentArea = currentArea * i;

                // * Updating the maxArea
                maxArea = max(maxArea, currentArea);
                break;
            }

            /*
            *   Otherwise,
            *   area = building height * (current index - index of building present at top of stack - 1)
            */
            currentArea = currentArea * (i - s.top() - 1);

            // * Updating the maxArea
            maxArea = max(maxArea, currentArea);
        }

        // * Pushing the current index to the stack
        s.push(i);
    }

    // * Returning the largest rectangle i.e. maxArea
    return maxArea;
}