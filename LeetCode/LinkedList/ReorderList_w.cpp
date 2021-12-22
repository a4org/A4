/*
 * LeetCode 143 Reorder List
 * Medium
 * Jiawei Wang
 * 2021 12.22
 */

#include <stack>

using namespace::std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
	// Seperate two Lists from middle (first is longer)
	ListNode* dummy = new ListNode(0); // a dummy node, trick
	dummy->next = head;

	int count = 0;
	ListNode* p = dummy;

	while (p->next) {
	    count++;
	    p = p->next;
	}

	ListNode* q = dummy;
	for (int i = 0; i < (count+1)/2; i++)
	    q = q->next;

	ListNode* head2 = q->next;
	q->next = NULL; // seperate

	head2 = reverseLinkedList(head2); // reverse head2

	p = head; q = head2;
	ListNode* h = dummy;

	while (p || q) {
	    if (p) {
		h->next = p;
		p = p->next;
		h = h->next;
	    }
	    
	    if (q) {
		h->next = q;
		q = q->next;
		h = h->next;
	    }
	}
    }

private:
    ListNode* reverseLinkedList(ListNode* head) {
	// A template reverse API
	// # -> O -> O -> O -> O
	// L <- C x 
	//      L <- C x
	//           L <- C x
	//		  L <- C x
	ListNode* curr = head;
	ListNode* last = NULL;
	ListNode* next;

	while (curr) {
	    next = curr->next;
	    curr->next = last;
	    last = curr;
	    curr = next;
	}

	return last;
    }
};

