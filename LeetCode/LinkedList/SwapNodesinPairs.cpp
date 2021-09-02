/*
 * LeetCode 24 Swap Nodes in Pairs
 * Medium
 * Shuo Feng
 * 2021.9.2
 */

#include<iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
/*
 * Solution 1: Iteration
 *   Find the node before ("pre_node"), swap the two nodes after " pre_node ", and change " pre_node " to the second node.
 *        0           A            B            C            D
 *        ↑pre_node(m)└───replace──┘
 *        0           B            A            C            D
 *        (m)                      ↑pre_node    └───replace──┘
 *        0           B            A            D            C
 *        (m)                                                ↑pre_node
 *        retrun m-> next;
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* m = new ListNode(0);
        m->next = head;

        ListNode* pre_node = new ListNode(0); // The node before.
        pre_node = m;
      
        // Two cases to stop, (1): no  node behind, 
        //                    (2): one node behind. ( notice: (2)after(1) ).
        while (pre_node->next != nullptr && pre_node->next->next != nullptr) {
            ListNode* node = new ListNode(0);
            
            // Swap two nodes after " pre_node ".
            node = pre_node->next;
            
            pre_node->next = node->next;
            node->next = pre_node->next->next;
            pre_node->next->next = node;
            pre_node = node;
        }
        return m->next;
    }
};

/*
 * Solution 2: Recursion
 *   Each step, connect head with the next node after " Next "(node after head), then connect head after Next.            
 *   
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // Two cases to stop, same sa solution 1.
        if (head != nullptr && head->next != nullptr) {
            ListNode* Next = new ListNode(0);
            Next = head->next;
            
            // " head->next "is the " Next " of the next two nodes.
            head->next = swapPairs(Next->next);
            Next->next = head;
            
            // " Next " is the front node.
            return Next;
        }
        else return head;
    }
};
