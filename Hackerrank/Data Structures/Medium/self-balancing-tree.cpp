/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Self Balancing Tree problem
*   Problem Link:- https://www.hackerrank.com/challenges/self-balancing-tree/problem
*/
/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

/*
*   This method will return the height of the tree,
*   If the node is NULL, it will return -1
*/
int height(node* root) {
    if(root==NULL) {
        return -1;
    } else {
        return root->ht;
    }
}

/*
*   This method will return the balance factor
*   of the tree by comparing the height of
*   left and right subtree. Balance factor of a NULL
*   node is returned as 0
*/
int getBalanceFactor(node* root) {
    if(root==NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

/*
*   This method will perform a left rotation on the tree
*   and will return the updated root node. It'll also update
*   the height of the nodes that are shuffled
*/
node* leftRotate(node* root) {

    node* a = root->right;
    node* b = a->left;

    a->left = root;
    root->right = b;

    root->ht = 1 + max(height(root->left), height(root->right));
    a->ht = 1 + max(height(a->left), height(a->right));

    return a;

}

/*
*   This method will perform a right rotation on the tree
*   and will return the updated root node. It'll also update
*   the height of the nodes that are shuffled
*/
node* rightRotate(node* root) {

    node* a = root->left;
    node* b = a->right;

    a->right = root;
    root->left = b;

    root->ht = 1 + max(height(root->left), height(root->right));
    a->ht = 1 + max(height(a->left), height(a->right));

    return a;

}

/*
*   This method will insert an element in AVL tree
*   and will balance that tree
*/
node* insert(node* root, int val) {

    /*
    *   If there is no element in the tree,
    *   create a new node with the given value
    *   and return that. Height of a leaf node will be 0
    */
    if(root == NULL) {
        node* n1 = new node();
        n1->val = val;
        n1->left = NULL;
        n1->right = NULL;
        n1->ht = 0;
        return n1;
    }

    /*
    *   If the given value to insert is less
    *   than value at root, insert that value in the
    *   left subtree
    */
    if(val < root->val) {
        root->left = insert(root->left, val);
    }

    /*
    *   If the given value to insert is more
    *   than value at root, insert that value in the
    *   right subtree
    */
    else if(val > root->val) {
        root->right = insert(root->right, val);
    }

    /*
    *   Otherwise, do nothing as the AVL should
    *   not contain duplicate elements
    */
    else {
        return root;
    }

    /*
    *   Update the height of the root node
    *   Height of current root node = maximum of (height of left subtree and height of right subtree) + 1
    */
    root->ht = 1 + max(height(root->left), height(root->right));

    // * Calculate the balance
    int balance = getBalanceFactor(root);

    // * Left Left Case -> Perform a right rotation
    if(balance > 1 && val < root->left->val) {
        return rightRotate(root);
    }

    /*
    *   Left Right Case
    *   -> Perform a left rotation on left subtree
    *   -> Perform a right rotation on root
    */
    if(balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // * Right Right Case -> Perform a left rotation
    if(balance < -1 && val > root->right->val) {
        return leftRotate(root);
    }

    /*
    *   Right Left Case
    *   -> Perform a right rotation on right subtree
    *   -> Perform a left rotation on root
    */
    if(balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // * Return the root
    return root;
}