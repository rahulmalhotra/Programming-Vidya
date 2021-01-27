/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Is This a Binary Search Tree? problem
*   Problem Link:- https://www.hackerrank.com/challenges/is-binary-search-tree/problem
*   Website:- www.programmingvidya.com
*/

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

/*
*   This function is used to perform inorder traversal of tree and
*   store the result in ans
*/
void inOrder(Node* root, vector<int> &ans) {

    /*
    *   If root is not NULL, call inOrder on subtrees
    *   and store the result in ans vector
    */
    if(root!=NULL) {
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
}

// * This function is used to check if a tree is BST or not
bool checkBST(Node* root) {

    // * Initializing ans vector
    vector<int> ans;

    // * If root is NULL, return true
    if(root==NULL) {
        return true;
    }

    /*
    *   Performing the inorder traversal of tree and
    *   storing the result in ans vector
    */
    inOrder(root, ans);

    // * Calculating the length of ans vector
    int length = ans.size();

    /*
    *   The inorder traversal of a BST is always sorted.
    *   Checking if the current element of ans vector is
    *   greater than or equal to the next element.
    *   If this is true, the tree is not a BST, return false
    */
    for(int i=0; i<length-1; i++) {
        if(ans[i] >= ans[i+1]) {
            return false;
        }
    }

    // * If the ans vector is sorted, this means the tree is a BST, return true
    return true;
}
