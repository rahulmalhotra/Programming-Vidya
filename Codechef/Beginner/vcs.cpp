/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef VCS Problem
*   Problem Link:- https://www.codechef.com/problems/VCS
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfTestCases, numberOfFiles, currentFile, ignoredCount,
    trackedCount, ignored[101] = {0}, tracked[101] = {0},
    trackedAndIgnoredCount, untrackedAndUnignoredCount;

    // * Accepting the number of test cases
    cin>>numberOfTestCases;

    // * Executing each test case one by one
    while(numberOfTestCases--) {

        /*
        *   Initializing tracked and ignored count, and
        *   Untracked and Unignored count to 0 for current test case
        */

        trackedAndIgnoredCount  = 0;
        untrackedAndUnignoredCount = 0;

        /*
        *   Accepting the number of files, ignored count and tracked count
        *   for the current test case
        */
        cin>>numberOfFiles;
        cin>>ignoredCount;
        cin>>trackedCount;

        // * Accepting files and marking them as ignored
        for(int i=1; i<=ignoredCount; i++) {
            cin>>currentFile;
            ignored[currentFile]++;
        }

        // * Accepting files and marking them as tracked
        for(int i=1; i<=trackedCount; i++) {
            cin>>currentFile;
            tracked[currentFile]++;
        }

        /*
        *   Looping all files, counting tracked and ignored files
        *   as well as untracked and unignored files for the current test case
        */
        for(int i=1; i<=numberOfFiles; i++) {
            if(
                ignored[i]==1 &&
                tracked[i]==1
            ) {
                trackedAndIgnoredCount++;
            } else if(
                ignored[i]==0 &&
                tracked[i]==0
            ) {
                untrackedAndUnignoredCount++;
            }
            // * Resetting tracked and ignored files to 0 for next test case
            ignored[i]=0;
            tracked[i]=0;
        }

        /*
        *   Displaying the tracked and ignored count,
        *   and untracked and unignored count for the current test case
        */
        cout<<trackedAndIgnoredCount<<" "<<untrackedAndUnignoredCount<<endl;
    }
}