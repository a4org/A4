/*
 * LeetCode 203 Remove Linked List Elements
 * Easy
 * Shuo Feng
 * 2021.11.12
 */

#include<iostream>
#include<vector>
using namespace std;


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
        ListNode* prehead = new ListNode();
        prehead->next = head;

        ListNode* pre = prehead;        
        ListNode* node = new ListNode(); // Node after pre.

        // Each time check node after pre.
        while (pre->next != nullptr) {
            node = pre->next;

            // Meet specified element -> change node after pre.
            if (node->val == val) {
                if (node->next != nullptr)
                    pre->next = pre->next->next;
                else
                    pre->next = nullptr;
            }
            else
                pre = pre->next;
        }
        return prehead->next;
    }
};
