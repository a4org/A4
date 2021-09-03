/*
 * LeetCode 83 Remove Duplicates from Sorted List
 * Easy
 * Shuo Feng
 * 2021.9.3
 */

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * Solution : Iteration.
 *   Compare value with the value of the next node, if equal delete the next node.
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* Node = head;
        while (Node && Node->next) {
            while (Node->next && Node->val == Node->next->val) {
                Node->next = Node->next->next;
            }
            // Updata
            Node = Node->next;
        }
        return head;
    }
};
