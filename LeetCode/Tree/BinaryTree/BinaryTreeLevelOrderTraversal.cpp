/*
 * LeetCode 102 Binary Tree Level Order Traversal
 * Medium
 * Shuo Feng
 * 2021 7.31
 */
 
 #include<iostream>
#include<vector>
using namespace std;
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
    vector<vector<int>> Out_Put;
    vector<vector<int>> levelOrder(TreeNode* root) {
        int i = 0;
        traverse(root, i);
        return Out_Put;
    }
    void traverse(TreeNode* root, int i) {
        if (!root)
            return;
        if (Out_Put.size() <= i)
            Out_Put.push_back(vector<int>{}); // Add a array for each new line
        Out_Put[i].push_back(root->val);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
};
