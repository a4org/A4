/*
 * LeetCode 563 Binary Tree Tilt
 * Easy
 * Shuo Feng
 * 2021.12.8
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
 *   Traverse once, find node`s tilt and the sum of all subtree value at the same time.
 */

class Solution {
private:
    int ans = 0;
    int helper(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left  = helper(root->left);
        int right = helper(root->right);
        ans += left > right ? left - right : right - left;

        return left + right + root->val;
    }

public:
    int findTilt(TreeNode* root) {
        if (root == nullptr)
            return 0;
        helper(root);
        return ans;
    }
};
