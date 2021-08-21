/*
 * LeetCode 117 Populating Next Right Pointers in Each Node ii
 * Medium
 * Shuo Feng
 * 2021.8.21
 */

/*
 * Solution 1: Bfs
 *   Level traverse the tree, storage the nodes which is on a same line in a queue.
 *   Use a node " before " to point to the before node, in each cycle, connect " before " with it`s next node, and updata " before " (line 56, 57, 58)
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* before = nullptr;  //point to the before node

            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (i >= 1) 
                    before->next = node;
                before = node;
            }
        }
        return root;
    }
};
