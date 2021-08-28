/*
 * LeetCode 19 Remove Nth Node From End of List
 * Medium
 * Shuo Feng
 * 2021.8.28
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

/* 
 * Solution 1: double pointers
 *   Finish in one pass
 *   Use two pointers, one point( node_2 ) to the place before head node, the another one ( node_1 ) point to the Nth node
 *  two pointers move tegether, when node_1 point to null pointer, the node after node_2 is the one to delete.
 *
 *         ano       1       2       3       4       5
 *         ↑node_2   ↑node_1
 *         ano       1       2       3       4       5
 *         ↑node_2                   ↑node_1
 *         ano       1       2       3       4       5
 *                   ↑node_2                 ↑node_1
 *         ano       1       2       3       4       5
 *                           ↑node_2                 ↑node_1
 *         ano       1       2       3       4       5       nullptr
 *                                   ↑node_2                 ↑node_1
 *         ano       1       2       3       5 (delete " 4 ")
 *                                   ↑node_2 
 *                   1       2       3       5
 *
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ano_head = new ListNode(0);
        ano_head->next = head;

        ListNode* node_1 = head;
        ListNode* node_2 = ano_head;
        
        for (int i = 0; i < n; ++i) {
            node_1 = node_1->next;
        }

        while (node_1 != nullptr) {
            node_1 = node_1->next;
            node_2 = node_2->next;
        }
        node_2->next = node_2->next->next;

        ListNode* m = ano_head->next;
        delete ano_head;
        return m;
    }
};
