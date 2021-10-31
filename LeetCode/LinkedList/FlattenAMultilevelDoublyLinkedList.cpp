/*
 * LeetCode 430 Flatten a Multilevel Doubly Linked List
 * Medium
 * Shuo Feng
 * 2021.10.31
 */

#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/*
 * Solution: Dfs.
 */

class Solution {
private: 
    // Return the last node in a list.
    Node* dfs(Node* head) {
        Node* last = head; // Last node.
        while (head != nullptr) {
            if (head->child == nullptr) {
                // Update last.
                last = head;
                head = head->next;
            }

            else if (head->child != nullptr) {
                Node* Child = head->child;     // Child list.
                Node* Child_tail = dfs(Child); // Last node of child list.
                Node* Next = head->next;

                head->next = Child;
                Child->prev = head;
                head->child = nullptr;

                Child_tail->next = Next;
                if (Next != nullptr)
                    Next->prev = Child_tail;

                last = head;
                head = Child_tail;
            }
        }
        return last;
    }

public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};
