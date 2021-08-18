/*
 * LeetCode 235 Lowest Common Ancestor of a Binary Search Tree
 * Easy
 * Shuo Feng 
 * 2021.8.18
 */
 
/*
 * Solution :dfs
 *  Acroding to binary search tree, value of left node should be smaller than root node, value of right node should be bigger than root node.
 * When meet these conditions at the same time , the root is the lowest common ancestor.
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
        if (!root) return nullptr;
        int value = root->val;
        int val_p = p->val;
        int val_q = q->val;

        if (val_p < value && val_q < value) return dfs(root->left, p, q);
        else if (val_p > value && val_q > value) return dfs(root->right, p, q);
        else return root;
    }
};
