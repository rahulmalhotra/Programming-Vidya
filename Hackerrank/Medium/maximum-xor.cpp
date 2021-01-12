/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Maximum Xor problem
*   Problem Link:- https://www.hackerrank.com/challenges/maximum-xor/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

/*
*   Setting maximum bit index as 31
*   considering a 32 bit integer
*/
int INT_SIZE = 31;

// * Node class to be used in a Trie
class Node {

    public:
    Node* left;
    Node* right;

    /*
    *   Constructor for the Node class,
    *   it will se the left and right pointer as NULL
    */
    Node() {
        left = NULL;
        right = NULL;
    }
};

// * Trie class
class Trie{

    // * Defining the root node
    Node* root;

    public:

    // * Initializing root node in Trie constructor
    Trie() {
        root = new Node();
    }

    // * Insert function to insert element in the trie
    void insert(int element) {

        // * Pointing current pointer to root node
        Node* current = root;

        /*
        *   Considering all the 32 bits in current element
        *   from left to right i.e. from MSB to LSB one by one
        */
        for(int i=INT_SIZE; i>=0; i--) {

            // * Calculating the current bit
            int bit = (element>>i) & 1;

            // * If the current bit is 1
            if(bit) {

                /*
                *   If we don't have a right child of the current node,
                *   initialize a new node and link it as the right child
                *   to the current node
                */
                if(current->right==NULL) {
                    current->right = new Node();
                }

                // * Move the current pointer to the right child
                current =  current->right;
            }

            // * Otherwise, if the current bit is a 0
            else {

                /*
                *   If we don't have a left child of the current node,
                *   initialize a new node and link it as the left child
                *   to the current node
                */
                if(current->left==NULL) {
                    current->left = new Node();
                }

                // * Move the current pointer to the left child
                current =  current->left;
            }
        }
    }

    /*
    *   Function to find out the maximum Xor pair
    *   of an element among all the elements present
    *   in the trie
    */
    int maximumXorPair(int element) {

        // * Pointing current pointer to root node
        Node* current = root;

        // * Initializing maximumXor variable to 0
        int maximumXor = 0;

        /*
        *   Considering all the 32 bits in current element
        *   from left to right i.e. from MSB to LSB one by one
        */
        for(int i=INT_SIZE; i>=0; i--) {

            // * Calculating the current bit
            int bit = (element>>i) & 1;

            // * If the current bit is 1
            if(bit) {

                /*
                *   If there is a node present to the left of current node,
                *   add the value contributed by the current bit as 1
                *   to the maximum xor as we can xor it with 0.
                *   Move the current pointer to the left child
                */
                if(current->left!=NULL) {
                    maximumXor += 1<<i;
                    current =  current->left;
                }

                /*
                *   Otherwise, move the current pointer to the right child
                *   as the current bit is 1 and we cannot find a 0.
                *   Therefore, it won't contribute anything to the maximum xor
                */
                else {
                    current = current->right;
                }
            }

            // * Otherwise, if the current bit is 0
            else {

                /*
                *   If there is a node present to the right of current node,
                *   add the value contributed by the current bit as 1
                *   to the maximum xor as we can xor it with 1.
                *   Move the current pointer to the right child
                */
                if(current->right!=NULL) {
                    maximumXor += 1<<i;
                    current =  current->right;
                }

                /*
                *   Otherwise, move the current pointer to the left child
                *   as the current bit is 0 and we cannot find a 1.
                *   Therefore, it won't contribute anything to the maximum xor
                */
                else {
                    current =  current->left;
                }
            }
        }

        // * Returning the maximum xor
        return maximumXor;
    }

};

// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {

    // * Initializing variables
    Trie t;
    vector<int> result;

    // * Inserting all the array elements in the trie one by one
    for(int element : arr) {
        t.insert(element);
    }

    /*
    *   Finding the maximum xor of all the queries
    *   one by one and pushing it to the result vector
    */
    for(int query : queries) {
        result.push_back(t.maximumXorPair(query));
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

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
