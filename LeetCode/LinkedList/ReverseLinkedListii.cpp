/*
 * LeetCode 92 Reverse Linked List ii
 * Medium
 * Shuo Feng
 * 2021.9.8
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
 *   Find the Left and Right node, cut the list that should be reversed, connect after reverse.
 *
 *      prehead ──────→ 1 ──────→ 2 ──────→ 3 ──────→ 4 ──────→ 5
 *
 *
 *      prehead ──────→ 1 ──────→ 2 ──────→ 3 ──────→ 4 ──────→ 5
 *                      ↑pre      ↑L                  ↑R        ↑ aft 
 * Cut:
 *      prehead ──────→ 1         2 ──────→ 3 ──────→ 4         5
 *                      ↑pre      ↑L                  ↑R        ↑ aft
 * Reverse:
 *      prehead ──────→ 1         4 ──────→ 3 ──────→ 2         5
 *                      ↑pre      ↑R                  ↑L        ↑ aft
 * Connect:
 *      prehead ──────→ 1 ──────→ 4 ──────→ 3 ──────→ 2 ──────→ 5
 *                      ↑pre      ↑R                  ↑L        ↑ aft
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prehead = new ListNode(0); // Node before head.
        prehead->next = head;
        ListNode* pre = prehead;  // Node before L
        ListNode* R = prehead;
         
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        for (int i = 0; i < right; ++i) {
            R = R->next;
        }
        ListNode* L = pre->next;
        ListNode* aft = R->next;
        
        // Cut the list.
        pre->next = nullptr;
        R->next = nullptr;
        
        // Connect.
        pre->next = reverseList(L);
        L->next = aft;

        return prehead->next;
    }
private:
  
    // Same as "ReverseLinkedList.cpp"
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = head;
        ListNode* Aft = nullptr;

        while (preNode != nullptr) {
            ListNode* Next = preNode->next;
            preNode->next = Aft;
            Aft = preNode;
            preNode = Next;
        }
      
        // Return the new head.
        return Aft;
    }
};
