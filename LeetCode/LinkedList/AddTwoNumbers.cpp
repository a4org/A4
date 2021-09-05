/*
 * LeetCode 2 Add Two Numbers
 * Medium
 * Shuo Feng
 * 2021.9.5
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
 *   Creat a list ( newhead ), add the numbers and connect after it.
 *   Use " sum " to storage the sum of two numbers.
 *
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(0); // 
        ListNode* Node = newhead;
        int sum = 0;
        
        // Condition: at least one of these two lists is not a nullptr, or need to carry.
        while (l1 != nullptr || l2 != nullptr || sum != 0) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Add it to the next node.
            Node->next = new ListNode(0);
            Node = Node->next;
            Node->val = sum % 10; 
            sum /= 10;  // Number to carry
        }
        return newhead->next;
    }
};
