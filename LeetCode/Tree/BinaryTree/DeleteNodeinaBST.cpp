/*
 * LeetCode 450 Delete Node in a BST
 * Medium
 * Shuo Feng
 * 2021.11.22
 */

#include<iostream>
#include<vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Solution: Dfs
 */

class Solution {
public:
    // Function: Search and delete node in a tree, return the root node.
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;

        if      (root->val > key)  // Search left  subtree.
            root->left  = deleteNode(root->left, key);
        else if (root->val < key)  // Search right subtree.
            root->right = deleteNode(root->right, key);

        // Find key:
        else if (root->val == key) {
            if (root->left  == nullptr) return root->right;
            if (root->right == nullptr) return root->left;

            // Move key node `s left subtree to the left most subnode of right subtree.
            TreeNode* node = root->right;
            while (node->left != nullptr)
                node = node->left;

            node->left = root->left;
            root = root->right;
        }
        return root;
    }
};
