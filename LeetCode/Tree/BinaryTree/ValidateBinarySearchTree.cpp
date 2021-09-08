/*
 * LeetCode 98 Validate Binary Search Tree
 * Medium
 * Shuo Feng
 * 2021.8.9
 * Last edited at 2021.9.8
 */

/*
 *   Inorder traverse the binary tree and record value of each nodes in 'list', if it is a valid binary search tree 
 *  the values in 'list' should be sorted from smallest to largest .
 */

#include<iostream>
#include<vector>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> list;
    bool isValidBST(TreeNode* root) {
        traverse(root);
     
        // Check whether "list" is a increasing sequence.
        for (int i = 1; i < list.size(); ++i) {
            if (list[i] <= list[i - 1]) return false;  // Binary tree is invalid
        }
        return true;
    }
 
    // Inorder traversal.
    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->left);
            list.push_back(root->val);
            traverse(root->right);
        }
        else return;
    }
};
