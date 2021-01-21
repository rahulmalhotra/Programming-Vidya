/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Tree : Top View problem
*   Problem Link:- https://www.hackerrank.com/challenges/tree-top-view/problem
*   Website:- www.programmingvidya.com
*/

#include<bits/stdc++.h>

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

    void topView(Node * root) {

        // * Initializing variables
        map<int, int> topViewMap;
        queue<pair<int, Node*>> q;

        // * Adding the root node to the queue with level 0
        q.push({0, root});

        // * Looping while queue is not empty
        while(!q.empty()) {

            // * Getting the front element from the queue
            pair<int, Node*> currentPair = q.front();

            // * Popping the front element from the queue
            q.pop();

            /*
            *   Adding the front element to the topViewMap with it's level
            *   as the key and the related node's data as the value.
            *   Note: If there is already an entry in the map with same key,
            *   this insert operation will be ignored automatically
            */
            topViewMap.insert({currentPair.first, currentPair.second->data});

            /*
            *   If the left child of current node is not NULL,
            *   add it to the queue with it's level decremented by 1
            */
            if(currentPair.second->left!=NULL) {
                q.push({currentPair.first - 1, currentPair.second->left});
            }

            /*
            *   If the right child of current node is not NULL,
            *   add it to the queue with it's level incremented by 1
            */
            if(currentPair.second->right!=NULL) {
                q.push({currentPair.first + 1, currentPair.second->right});
            }
        }

        /*
        *   As we're using an ordered map, the elements are sorted according
        *   to their levels. Therefore, printing the top view of the tree
        *   from left to right
        */
        for(auto p : topViewMap) {
            cout<<p.second<<" ";
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

	myTree.topView(root);
    return 0;
}
