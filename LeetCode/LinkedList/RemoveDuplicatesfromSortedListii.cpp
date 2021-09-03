/*
 * LeetCode 82 Remove Duplicates from Sorted List ii.
 * Medium
 * Shuo Feng
 * 2021.9.3
 */

#include<iostream>
#include<vector>
using namespace std;

//definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * Solution 1: Iteration.
 *   Creat two nodes, one point to the node before( "preNode" ), one point to the node we are checking( "Node" )(check nodes after "preNode").
 *   When find duplicates, search the last node that has the same value, acording to the last one we can determine the new place of "preNode".
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* Node = head;
        ListNode* preNode = prehead;

        while (Node) {
            if (Node->next != nullptr && Node->val == Node->next->val) {
                int value = Node->val;
                
                // Find the last one
                while (Node->next && Node->next->val == value)
                    Node = Node->next;
            }
          
            // "preNode" and "Node" close together --> no duplicates.
            if (preNode->next == Node) {
                preNode = preNode->next;
            }
            else {
                preNode->next = Node->next;
            }
          
            // Updata "Node".
            Node = Node->next;
        }
        return prehead->next;
    }
};

/*
 * Solution 2: Recursion.
 *   When reach duplicates, find the last node that has the same value, enter the next level from it(delete the node before the last one),
 *  otherwise enter next level from the next node.
 *  (Always return the head node when back to up one level).
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // Stop condition : no node / only one node.
        if (head == nullptr || head->next == nullptr) return head;
        
        if (head->val == head->next->val) {
            int value = head->val;
            
            // Find the last node that has the same value
            ListNode* Node = head->next;
            while (Node && Node->val == value) {
                Node = Node->next;
            }
            return deleteDuplicates(Node);
        }
      
        // No duplicates.
        else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
