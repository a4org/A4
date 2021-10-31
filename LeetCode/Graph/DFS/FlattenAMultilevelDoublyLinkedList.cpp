/* 
 * LeetCode 430 Flatten a Multilevel Doubly Linked List
 * Medium
 * Jiawei Wang
 * 2021.10.31 
 */

using namespace::std;
    
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }

    Node* helper(Node* h) {   
        // return the end pointer
        if (h==NULL) return NULL;

        Node* next = h->next;
        Node* child = h->child;
        h->child = NULL;

        if (child==NULL && next==NULL)
            // end of the line return last pointer
            return h;
        else if (child!=NULL && next==NULL) {
            h->next = child;
            child->prev = h;
            
            Node* childEnd = helper(child); // get new end
            return childEnd;
        }
        else if (child==NULL && next!=NULL) {
            // just go through next
            Node* nextEnd = helper(next);
            return nextEnd;
        }
        else {
            // both are Non-NULL
            h->next = child;
            child->prev = h;
            
            Node* childEnd = helper(child);            
            childEnd->next = next;
            next->prev = childEnd;
            return helper(next);
        }
    }
};
