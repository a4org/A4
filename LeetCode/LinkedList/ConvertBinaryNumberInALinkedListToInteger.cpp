/*
 * LeetCode 1290 Convert Binary Number in a Linked List to Integer
 * Easy
 * Jiawei Wang
 * 2021 12.07
 */

#include <math.h>

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
    int getDecimalValue(ListNode* head) {
	int n = 0;
	int ret = 0;
	ListNode* init = head;
        while (head != nullptr) {
	    n++;
	    head = head->next;
	}

	while (init != nullptr) {
	    if (head->val) ret += pow(2, n);
	    n--;
	    init = init->next;
	}

	return ret;
    }
};
 
