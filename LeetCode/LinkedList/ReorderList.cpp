/*
 * LeetCode 143 Reorder List
 * Medium
 * Shuo Feng
 * 2021.9.11
 */

#include<iostream>
#include<vector>

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
 *   Divide the list into two sub-lists from mid node, reverse the second list, after merage the list is the one we need.
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* prehead = new ListNode(0);
        ListNode* fast = head;
        ListNode* slow = head;

        // Search the mid node
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* Node = slow->next; // The head node of second list.
        slow->next = nullptr;        // Cut

        // The new head 2 after reverse.
        ListNode* head_2 = reverseList(Node);
  
        // Storage the node after.
        ListNode* aft_1 = new ListNode(0);
        ListNode* aft_2 = new ListNode(0);
        
        // Merage two list in specific way
        while (head != nullptr && head_2 != nullptr) {
            
            // Update.
            // Record the node after. 
            aft_1 = head->next;
            aft_2 = head_2->next;

            // Connect alternately.
            head->next = head_2;
            head = aft_1;

            head_2->next = head;
            head_2 = aft_2;
        }
    }

private:
    // Reverse a list, same as LeetCode 206 Reverse Linked list.
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = head;
        ListNode* Aft = nullptr;

        while (preNode != nullptr) {
            ListNode* Next = preNode->next;
            preNode->next = Aft;
            Aft = preNode;
            preNode = Next;
        }
        // Return the new head node after reverse.
        return Aft;
    }
};
