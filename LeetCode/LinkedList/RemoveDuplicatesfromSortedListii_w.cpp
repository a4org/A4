/*
 * LeetCode 82 Remove Duplicates from Sorted List ii.
 * Medium
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
    // 0ms 100% the fastest dfs
    ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr) return nullptr;

	if (head->next && head->next->val == head->val) {
	    while (head) {
		// find first head element
		if (head->next && head->next->next == nullptr && head->next->val != head->val) {
		    head = head->next;
		    break;
		}
		if (head->next && head->val != head->next->val && head->next->next->val != head->next->val) {
		    head = head->next;
		    break;
		} 
		head = head->next;
	    }
	}

	if (head == nullptr) return nullptr;

	helper(head->next, head, head->val); // last val

	return head;
    }

private:
    void helper(ListNode* node, ListNode* beforeNode, int val) { 
	// beforeNode stands for the correct node before this duplicates num
	if (node == nullptr) {
	    beforeNode->next = nullptr;
	    return;
	}

	if (node->val == val) {
	    helper(node->next, beforeNode, val);
	} else {
	    if (node->next == nullptr || node->next->val != node->val) {
		// if node is a single element
		// update new state
		beforeNode->next = node;
		// node becomes the new beforeNode
		helper(node->next, node, node->val);
	    } else {
		helper(node->next, beforeNode, node->val);
	    } 
	}
    }
};



