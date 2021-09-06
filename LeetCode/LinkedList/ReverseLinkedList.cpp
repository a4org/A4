/*
 * LeetCode 206 Reverse Linked list
 * Easy
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
 * Solution:
 *   
 *           0         A ─────→  B ─────→  C ─────→  D ─────→  E         0
 *           ↑Aft      ↑preNode  ↑Next
 *       
 *           0  ←───── A         B ─────→  C ─────→  D ─────→  E         0
 *                     ↑Aft      ↑preNode  ↑Next
 *
 *           0  ←───── A  ←───── B         C ─────→  D ─────→  E         0
 *                               ↑Aft      ↑preNode  ↑Next
 *
 *           0  ←───── A  ←───── B  ←───── C         D ─────→  E         0
 *                                         ↑Aft      ↑preNode  ↑Next
 *
 *           0  ←───── A  ←───── B  ←───── C  ←───── D         E         0
 *                                                   ↑Aft      ↑preNode  ↑Next
 *
 *           0  ←───── A  ←───── B  ←───── C  ←───── D  ←───── E         0                 --> return Aft;
 **                                                            ↑Aft      ↑preNode  ↑Next
 *
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = head;
        ListNode* Aft = nullptr;

        while (preNode != nullptr) {
            ListNode* Next = preNode->next;
            preNode->next = Aft;
            Aft = preNode;
            preNode = Next;
        }
        return Aft;
    }
};
