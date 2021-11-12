/*
 * LeetCode 83 Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr) return nullptr;
	helper(head->next, head);
	return head;
    }
private:
    void helper(ListNode* node, ListNode* firstNode) {
	if (node == nullptr) {
	    firstNode->next = node;
	    return;
	}

	if (node->val == firstNode->val) {
	    helper(node->next, firstNode);
	} else {
	    firstNode->next = node;
	    helper(node->next, node);
	}
    }
};

