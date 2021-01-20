/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Tree: Height of a Binary Tree problem
*   Problem Link:- https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {

        // * If root is NULL, return -1
        if(root==NULL) {
            return -1;
        }

        // * Return the maximum of (height of left subtree or height of right subtree) + 1
        return max(height(root->left), height(root->right)) + 1;
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.height(root);

  	std::cout << height;

    return 0;
}
