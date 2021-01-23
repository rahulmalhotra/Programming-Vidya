/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Binary Search Tree : Insertion problem
*   Problem Link:- https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
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

  	void preOrder(Node *root) {

      	if( root == NULL )
          	return;

      	std::cout << root->data << " ";

      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as

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

*/

    Node * insert(Node * root, int data) {

        /*
        *   If root is NULL, return new node as
        *   the root node with current data
        */
        if(root==NULL) {
            return new Node(data);
        }

        // * Otherwise, if data is less than data of root node
        else if(data<root->data) {

            // * Move to the left subtree
            root->left = insert(root->left, data);
        }

        // * Otherwise, if data is greater than data of root node
        else if(data>root->data) {

            // * Move to the right subtree
            root->right = insert(root->right, data);
        }

        // * Return the root node
        return root;
    }
};

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

    myTree.preOrder(root);

    return 0;
}
