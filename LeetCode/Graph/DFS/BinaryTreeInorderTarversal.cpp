/*
 * LeetCode 94 Binary Tree Inorder Tarversal
 * Easy
 * Shuo Feng
 * 2021.8.12
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
    vector<int> out_come;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return out_come;
    }
    void dfs (TreeNode* root){
        if (!root) return;
        dfs (root-> left);
        out_come.push_back(root->val);
        dfs (root-> right);
    }
};
