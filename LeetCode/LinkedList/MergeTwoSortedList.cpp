/*
 * LeetCode 21 Merge Two Sorted List
 * Easy
 * Shuo Feng
 * 2021.8.29
 * Last edited at 2021.9.4
 */

#include<iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // If one of the linked list is empty, result after merge is the another list.
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        
        // From head to end, find the point with smaller value, sort remainder after it.
        else if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};
