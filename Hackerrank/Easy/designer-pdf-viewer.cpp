/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Designer PDF Viewer problem
*   Problem Link:- https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
*/
int designerPdfViewer(vector<int> h, string word) {

    // * Initializing variables
    int maxHeight = 0;

    /*
    *   Iterating letters of the word one by one,
    *   Calculating the index of current letter and the height
    *   stored at that index. If the height of current letter
    *   is more than maximum height, update the maximum height
    *   with the height of current letter
    */
    for(int i=0; i<word.size(); i++) {
        if(h[word[i]-'a'] > maxHeight) {
            maxHeight = h[word[i]-'a'];
        }
    }

    /*
    *   Returning the area which will be
    *   maximum height * total number of letters
    *   in the given word
    */
    return maxHeight * word.size();
}