/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Game of Two Stacks Problem
*   Problem Link:- https://www.hackerrank.com/challenges/game-of-two-stacks/problem
*/
int twoStacks(int x, vector<int> a, vector<int> b) {

    // * Initializing Variables
    long long sum = 0, asize = a.size(), bsize = b.size();
    int count, i, j;

    // * Considering the first stack and calculating count for maximum valid sum
    for(i=0; i<asize; i++) {
        sum += a[i];
        if(sum>x) {
            sum-=a[i];
            break;
        }
    }

    // * Storing the count calculated from first stack
    count = i;

    /*
    *   Considering each element one by one from the second stack
    *   and adding it's value to the sum.
    *   If the sum is greater than maximum valid sum 'x'
    *   and we have elements left in the first stack,
    *   subtract the last element of first stack from the sum.
    *   If the sum is less than or equal to x,
    *   check if the current count is more than previously stored count
    *   and update the count variable
    */
    for(j=0; j<bsize; j++) {
        sum += b[j];
        if(sum>x && i>0) {
            sum -= a[--i];
        } else if(sum>x) {

            /*
            *   If the sum is more than maximum possible sum 'x'
            *   and we don't have any element to be removed from first stack
            *   break the loop as we cannot consider the current element in the second stack
            */
            break;
        }
        count = (sum<=x) ? max(count, i+j+1) : count;
    }

    // * Returning the final count
    return count;
}