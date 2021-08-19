/*
 * LeetCode 226 Invert Binary Tree
 * Easy
 * Shuo Feng
 * 2021.8.19
 */

/*
 * Solution 1: Bfs
 */


#include<iostream>
#include<vector>
#include<queue>
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
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();

                TreeNode* p = node->left;
                node->left = node->right;
                node->right = p;

                if (node->left)  q.push(node->left);
                if (node->right)  q.push(node->right);
            }
        }
        return root;
    }
};

/*
 * Solution 2: Dfs
 * The better way
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invertTree(root-> left);
        
        TreeNode* p = root-> left;
        root-> left = root-> right;
        root-> right = p;
        
        // After invert.
        invertTree(root-> left);
        return root;
    }
};
