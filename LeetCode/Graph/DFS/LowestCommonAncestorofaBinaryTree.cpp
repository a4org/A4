/*
 * LeetCode 236 Lowest Common Ancestor of a Binary Tree
 * Medium
 * Shuo Feng
 * 2021.8.18
 */

/*
 * Solution :bfs
 * Begin with root node, search the left subtree and the right subtree, 
 *
 * About line 43, 44:
 * Two cases to consider:  one node located in one of the the subtree, 
 *                         two node located in one of the sub tree, return the common ancestor to upper.
 */

#include<iostream>
#include<vector>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root == p || root == q) return root;

        TreeNode* left  = dfs(root->left , p, q); // Record the condition of left and right subtree on this node.
        TreeNode* right = dfs(root->right, p, q);

        if (!left) return right; // If did not find in one side, return the another side.
        if (!right) return left;
        return root; // left != nullptr and right != nullptr , p & q are on either side.
    }
};
