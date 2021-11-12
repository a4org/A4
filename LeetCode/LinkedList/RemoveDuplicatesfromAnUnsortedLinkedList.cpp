/*
 * LeetCode 1836 Remove Duplicates From an Unsorted Linked List
 * Medium
 * Jiawei Wang
 * 2021 11.12
 */

#include <unordered_set>

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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
	if (head == nullptr) return nullptr;
	unordered_set<int> duplicates;
	unordered_set<int> duplicate;
	getDuplicates(head, duplicates, duplicate);

	// find the first valid node
	while (head) {
	    if (duplicate.find(head->val) == duplicate.end()) {
		break;
	    }
	    head = head->next;
	}

	if (head == nullptr) return nullptr;

	helper(head->next, duplicate, head);

	return head;
    }

private:
    void getDuplicates(ListNode* node, unordered_set<int>& duplicates, unordered_set<int>& duplicate) {
	// build a data structure
	int val;
	while (node) {
	    val = node->val;
	    if (duplicates.find(val) != duplicates.end()) {
		duplicate.insert(val);
	    } else {
		duplicates.insert(val);
	    }
	    node = node->next;
	}
    }

    void helper(ListNode* node, unordered_set<int>& duplicate, ListNode* firstNode) {
	if (node == nullptr) {
	    // Termination Condition
	    firstNode->next = nullptr;
	    return;
	}

	if (duplicate.find(node->val) == duplicate.end()) {
	    // update status
	    firstNode->next = node;
	    helper(node->next, duplicate, node);
	} else{
	    helper(node->next, duplicate, firstNode);
	}
    }
};
