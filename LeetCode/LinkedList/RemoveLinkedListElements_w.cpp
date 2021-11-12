/*
 * LeetCode 203 Remove Linked List Elements
 * Easy
 * Jiawei Wang
 * 2021 11.12
 */

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
    ListNode* removeElements(ListNode* head, int val) {
	if (head == nullptr) return nullptr;
	while (head) {
	    if (head->val != val) break;
	    head = head->next;
	}
	if (head == nullptr) return nullptr;

	helper(head->next, val, head);

	return head;
    }

private:
    void helper(ListNode* node, int val, ListNode* firstNode) {
	if (node == nullptr) {
	    firstNode->next = nullptr;
	    return;
	}

	if (node->val != val) {
	    // update
	    firstNode->next = node;
	    helper(node->next, val, node);
	} else {
	    helper(node->next, val, firstNode);
	}
    }
};
