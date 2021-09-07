/*
 * LeetCode 148 Sort List
 * Medium
 * Shuo Feng
 * 2021.9.7
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
 * Solution :
 *   split the list into some sub list, combine after sort.
 *
 *            4 ─────→ 2 ─────→ 1 ─────→ 3
 *    split ↓
 *            4 ─────→ 2        1 ─────→ 3
 *    split ↓      
 *            4        2        1        3
 *    sort  ↓
 *            2 ─────→ 4        1 ─────→ 3
 *    sort  ↓
 *            1 ─────→ 2 ─────→ 3 ─────→ 4
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Acording to situation of only one node, the place after should be consider.
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
      
        // After split: list1 start with head, list2 start with node after slow node
        ListNode* head_1 = head;
        ListNode* head_2 = slow->next;
        slow->next = nullptr; // Cutting off.

        ListNode* Node_1 = sortList(head_1);
        ListNode* Node_2 = sortList(head_2);
    
        return Sort(Node_1, Node_2);
    }
    
    // Similar to LeetCode 21 Merge Two Sorted List
    ListNode* Sort(ListNode* Node_1, ListNode* Node_2) {
        if      (Node_1 == NULL) return Node_2;
        else if (Node_2 == NULL) return Node_1;

        else if (Node_1->val > Node_2->val) {
            Node_2->next = Sort(Node_1, Node_2->next);
            return Node_2;
        }
        else {
            Node_1->next = Sort(Node_1->next, Node_2);
            return Node_1;
        }
    }
};
