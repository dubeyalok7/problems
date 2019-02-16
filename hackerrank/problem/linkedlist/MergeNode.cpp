/*
 * MergeNode.cpp
 *
 *  Created on: 29-Nov-2018
 *      Author: dubeyalo
 */
#include <bits/stdc++.h>

using namespace std;
#if 0
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

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& cout) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
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

void traversal(SinglyLinkedListNode *node, vector<int> &vec)
{
	if(node == NULL)
		return;
	vec.push_back(node->data);
	traversal(node->next, vec);
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	vector<int> v1, v2;
	traversal(head1, v1);
	traversal(head2, v2);
	for(int i=v1.size()-1, j=v2.size()-1;i>=0, j>=0;i--,j--){
		if(v1[i]!= v2[j])
			return v1[i+1];
	}
}

int MergeNode()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

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

        cout << result << "\n";
    }

    //fout.close();

    return 0;
}
#endif
