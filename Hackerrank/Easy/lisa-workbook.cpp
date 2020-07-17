/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Lisa's Workbook Problem
*   Problem Link:- https://www.hackerrank.com/challenges/lisa-workbook/problem
*/
int workbook(int n, int k, vector<int> arr) {

    // * Initializing variables
    int pageNumber = 1, totalChapters = arr.size(), i = 0, startingProblem = 1, numberOfProblems, numberOfSpecialProblems = 0;

    // * Considering each chapter one by one
    while(i<totalChapters) {

        // * Initializing starting problem number to 1 on the current page
        startingProblem = 1;

        // * Accepting the number of problems in the current chapter
        numberOfProblems = arr[i];

        /*
        *   While the starting problem number on the current page is less than
        *   or equal to the total number of problems in the current chapter
        */
        while(startingProblem <= numberOfProblems) {

            /*
            *   If the starting problem number is less than or equal to the current page number
            *   and the current page number is less than or equal the ending problem number on the same page.
            *   The ending problem number on the current page = starting problem number + k - 1.
            *   And, the current page number is less than or equal to the total number of problems in
            *   the current chapter, we find a special problem.
            */
            if(
                startingProblem <= pageNumber &&
                pageNumber < startingProblem+k &&
                pageNumber <= numberOfProblems
            ) {
                numberOfSpecialProblems++;
            }

            // * Incrementing the page number by 1
            pageNumber++;

            // * Getting the starting problem number of the next page
            startingProblem += k;
        }

        // * Incrementing the chapter count by 1 to consider the next chapter
        i++;
    }

    // * Returning the number of special problems
    return numberOfSpecialProblems;
}