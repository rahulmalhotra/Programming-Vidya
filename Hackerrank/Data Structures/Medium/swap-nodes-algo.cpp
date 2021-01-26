/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Swap Nodes [Algo] problem
*   Problem Link:- https://www.hackerrank.com/challenges/swap-nodes-algo/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>

using namespace std;

// * Defining the Node class
class Node {

    public:

    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// * Defining the Tree class
class Tree{

    Node* root;

    public:

    // * This method is used to build the tree from the given indexes
    Node* build(vector<vector<int>> indexes) {

        // * Initializing variables
        queue<Node*> q;
        int i=0;

        // * Adding the root node of the tree to the queue
        root = new Node(1);
        q.push(root);

        // * Looping while queue is not empty
        while(!q.empty()) {

            // * Getting the current node from the front of the queue
            Node* current = q.front();

            // * Popping the front element from the queue
            q.pop();

            /*
            *   If the data is not -1, adding a new node
            *   as the left child of the current node,
            *   pushing the new node into the queue
            */
            if(indexes[i][0] != -1) {
                current->left = new Node(indexes[i][0]);
                q.push(current->left);
            }

            /*
            *   If the data is not -1, adding a new node
            *   as the right child of the current node,
            *   pushing the new node into the queue
            */
            if(indexes[i][1] != -1) {
                current->right = new Node(indexes[i][1]);
                q.push(current->right);
            }

            // * Incrementing i by 1
            i++;
        }

        // * Returning the root of the tree
        return root;
    }

    /*
    *   This method is used to swap tree nodes
    *   at depths which are multiple of k
    */
    void swapNodes(Node* root, int depth, int currentK, int initialK) {

        // * If root is NULL, return
        if(root==NULL) {
            return;
        }

        /*
        *   If the current depth is equal to currentK,
        *   swap the left and right subtrees and
        *   increment the value of currentK by initialK
        */
        if(depth == currentK) {
            Node* temp = root->left;
            root->left = root->right;
            root->right = temp;
            currentK += initialK;
        }

        // * Traversing to the left subtree and incrementing depth by 1
        swapNodes(root->left, depth+1, currentK, initialK);

        // * Traversing to the right subtree and incrementing depth by 1
        swapNodes(root->right, depth+1, currentK, initialK);
    }

    /*
    *   This method is used to perform inorder traversal of the tree
    *   and add the node's data to the result vector while traversing
    */
    void inOrder(Node* root, vector<int> &result) {

        // * If the root is NULL, return
        if(root==NULL) {
            return;
        }

        // * Performing the inOrder traversal on left subtree
        inOrder(root->left, result);

        // * Adding the root node's data to the result vector
        result.push_back(root->data);

        // * Performing the inOrder traversal on right subtree
        inOrder(root->right, result);
    }
};

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

    // * Initializing variables
    vector<vector<int> > result;
    Tree t;

    // * Building the binary tree using indexes
    Node* root = t.build(indexes);

    // * Iterating the queries one by one
    for(vector<int>::iterator it = queries.begin(); it != queries.end(); it++) {

        // * Swapping the nodes of tree at depths which are multiples of current query k
        t.swapNodes(root, 1, *it, *it);

        /*
        *   Performing the inorder traversal of tree after swapping nodes
        *   and storing the result in vector res
        */
        vector<int> res;
        t.inOrder(root, res);

        // * Adding the vector res to result vector
        result.push_back(res);
    }

    // * Returning the result vector
    return result;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
