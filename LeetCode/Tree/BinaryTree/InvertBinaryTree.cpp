/* 
 * LeetCode 226 Invert Binary Tree
 * Easy
 * Jiawei Wang
 * 2021.10.26
 */


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    // dfs
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* lleft = root->left;
        root->left = root->right;
        root->right = lleft;
        
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
