/*
 * LeetCode 61 Rotate List
 * Medium
 * Shuo Feng
 * 2021.9.9
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
 * Solution:
 *   Find the last node, connect it with the head node to form a list cycle.
 *   When rotate the list to the right by " k " places, the newhead is where head node move left " k " times( move right size - " k "times ).
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || (head == nullptr || head->next == nullptr)) return head;

        ListNode* Node = head;
        int size = 1; // Include head node.

        // Count the size of list.
        while (Node != nullptr && Node->next != nullptr) {
            Node = Node->next;  // Pointer to the last node.
            size += 1;
        }
      
        // Creat the list cycle.
        Node->next = head;
        
        
        k %= size; // Avoid the situation of " size < k ".
        for (int i = 0; i < size - k; ++i) {
            head = head->next;
            Node = Node->next;
        }
        // Break the list cycle.
        Node->next = nullptr;
        return head;
    }
};
