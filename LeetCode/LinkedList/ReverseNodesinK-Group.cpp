/*
 * LeetCode 25 Reverse Nodes in k-Group
 * Hard
 * Shuo Feng
 * 2021.9.6
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
 * Solution :Recursion.
 *   Determine the group to reverse by "start" and "end", each time reverse current group, after connect remaining list, return the head node to previous.
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;

        ListNode* start = head;  // Head Node of this Group.
        ListNode* end = start;
        
        // Search the node("end") after the last onde in group, as the head node of next group, also use to end the reverse in this round.
        // If not find, can not reverse, return the head node of the group.
        for (int i = 0; i < k; ++i) {
            if (end == nullptr) return head;
            end = end->next;
        }

        ListNode* newhead = reverse(start, end);
        // Begin with " start ", connect other nodes from " end ".
        start->next = reverseKGroup(end, k);
        return newhead;
    }
    
    // Reverse a sub linked list, same as LeetCode 206 Reverse Linked list.
    // Reverse the list before " end ", after reverse the last node is " start ", return the new head: " Aft ".
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* Aft = nullptr;
        ListNode* head = start;

        while (head != end) {
            ListNode* Next = head->next;
            head->next = Aft;
            Aft = head;
            head = Next;
        }
        return Aft;
    }
};
