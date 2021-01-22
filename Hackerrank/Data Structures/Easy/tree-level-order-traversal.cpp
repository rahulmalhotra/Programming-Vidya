/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Tree: Level Order Traversal problem
*   Problem Link:- https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
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
/*
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

    void levelOrder(Node * root) {

        // * Initializing variables
        queue<Node*> q;
        Node* currentNode;

        // * If root is NULL, return
        if(root==NULL) {
            return;
        }

        // * Add root node to the queue
        q.push(root);

        // * Loop while queue is not empty
        while(!q.empty()) {

            /*
            *   Getting the front element from the queue
            *   and assigning it to the current node
            */
            currentNode = q.front();

            // * Popping the front element from the queue
            q.pop();

            // * Displaying the data of the current node
            cout<<currentNode->data<<" ";

            /*
            *   If the left child of the current node is not NULL,
            *   pushing it into the queue
            */
            if(currentNode->left!=NULL) {
                q.push(currentNode->left);
            }

            /*
            *   If the right child of the current node is not NULL,
            *   pushing it into the queue
            */
            if(currentNode->right!=NULL) {
                q.push(currentNode->right);
            }
        }
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

	myTree.levelOrder(root);
    return 0;
}
