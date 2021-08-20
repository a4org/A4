/*
 * LeetCode 116 Populating Next Right Pointers in Each Node
 * Medium
 * Shuo Feng
 * 2021.8.20
 */

/*
 * Solution 1
 * For the node which is connected with next node, connect it`s right node and the left node of the next one.
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
        root->next = nullptr;

        Node* head = root;  // Point to the first node in each lines

        while (head->left != nullptr) {
            Node* node = head;
            while (node != nullptr) {

                node->left->next = node->right;
                if (node->next != nullptr)
                    node->right->next = node->next->left;
                node = node->next;
            }
            head = head->left;
        }
        return root;
    }
};


/*
 * Solution 2: bfs
 * The faster way
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q; // Queue to storage all node in a line
        q.push(root); 

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();

                if (node->left != nullptr && node->right != nullptr) {
                    node->left->next = node->right;
                    q.push(node->left);
                    q.push(node->right);
                }
                if (node->next != nullptr && node->right != nullptr)
                    node->right->next = node->next->left;
            }
        }
        return root;
    }
};
