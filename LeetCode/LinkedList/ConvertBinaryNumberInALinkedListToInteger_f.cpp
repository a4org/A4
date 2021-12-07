/*
 * LeetCode 1290 Convert Binary Number In A Linked List To Integer
 * Easy
 * Shuo Feng
 * 2021.12.7
 */

#include<iostream>
#include<vector>
#include<stack>
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
 * Solution 1: Stack.
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> binary;
        while (head != nullptr) {
            binary.push(head->val);
            head = head->next;
        }

        int x = 1;
        int ans = 0;
        while (!binary.empty()) {
            int bit = binary.top();
            ans += bit * x;
            x *= 2;
            binary.pop();
        }
        return ans;
    }
};

/*
 * Better Solution:
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};
