/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Find Merge Point of Two Lists problem
*   Problem Link:- https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    // * Initializing pointers and variables
    SinglyLinkedListNode* ptr1 = head1, *ptr2 = head2;
    int lengthOfList1 = 0, lengthOfList2 = 0, difference;

    // * Calculating the length of first linked list
    while(ptr1!=NULL) {
        ptr1 = ptr1->next;
        lengthOfList1++;
    }

    // * Calculating the length of second linked list
    while(ptr2!=NULL) {
        ptr2 = ptr2->next;
        lengthOfList2++;
    }

    // * Setting pointer 1 and pointer 2 back to head1 and head2
    ptr1 = head1;
    ptr2 = head2;

    /*
    *   If the length of first linked list is more than
    *   the length of second linked list, move the pointer 1
    *   d steps ahead, where d is the difference between
    *   length of first and second linked list
    */
    if(lengthOfList1>lengthOfList2) {
        difference = lengthOfList1 - lengthOfList2;
        while(difference--) {
            ptr1 =  ptr1->next;
        }
    }

    /*
    *   Otherwise, if the length of second linked list is more than
    *   the length of first linked list, move the pointer 2
    *   d steps ahead, where d is the difference between
    *   length of second and first linked list
    */
    else if(lengthOfList2>lengthOfList1) {
        difference = lengthOfList2 - lengthOfList1;
        while(difference--) {
            ptr2 =  ptr2->next;
        }
    }

    /*
    *   Now, moving both the pointer 1
    *   and pointer 2 simultaneously
    */
    while(ptr1!=NULL && ptr2!=NULL) {

        /*
        *   If at any instant, the pointer 1
        *   and pointer 2 both are equal,
        *   then this is the node where both the list 1
        *   and list 2 are merging. Returning it's data
        */
        if(ptr1==ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    /*
    *   If no such node is found where the
    *   lists are merging, return -1
    */
    return -1;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

      	SinglyLinkedListNode* ptr1 = llist1->head;
      	SinglyLinkedListNode* ptr2 = llist2->head;

      	for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
          		ptr1 = ptr1->next;
            }
        }

      	for (int i = 0; i < llist2_count; i++) {
          	if (i != llist2_count-1) {
          		ptr2 = ptr2->next;
            }
        }

      	ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
