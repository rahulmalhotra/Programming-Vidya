/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Inserting a Node Into a Sorted Doubly Linked List problem
*   Problem Link:- https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

    // * Initializing pointers
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data), *current = head;

    // * If head is NULL, return newNode
    if(head==NULL) {
        return newNode;
    }

    /*
    *   Otherwise, if data is less than or equal to
    *   the data of head node, inserting the new node
    *   at the beginning of the list and returning that
    */
    else if(data<=head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    /*
    *   Otherwise, insert the new node somewhere
    *   inside the list or at the end of the list
    */
    else {

        /*
        *   Looping while the next node of the
        *   current node is not NULL
        */
        while(current->next!=NULL) {

            /*
            *   If the data is greater than the current node's data
            *   and the data is less than or equal to the next node's data.
            *   This means that we can keep the newNode between the current node
            *   and the next node. Adding it there and returning head
            */
            if(data>current->data && data<=current->next->data) {
                newNode->prev = current;
                newNode->next = current->next;
                current->next = newNode;
                return head;
            }

            // * Moving the current node to the next node
            current = current->next;
        }

        /*
        *   Now as we reached the last node,
        *   marking the next of current node as the new node
        *   and the previous of new node as the current node.
        *   Returning head
        */
        current->next = newNode;
        newNode->prev = current;
        return head;
    }
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
