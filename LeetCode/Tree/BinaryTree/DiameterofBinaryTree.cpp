/*
 * LeetCode 543 Diameter of Bianry Tree
 * Easy
 * Shuo Feng
 * 2021.10.11
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
 * Solution: Dfs.
 */

class Solution {
    private:
        int max_diameter = 0;
  
        int dfs(TreeNode* root) {
            // The next node dose no exits -> remove path
            if (root == nullptr) return -1;
          
            // Add path when move to next node.
            int left  = dfs(root->left ) + 1;
            int right = dfs(root->right) + 1;

            // Update the maximum diameter.
            max_diameter = max(max_diameter, left + right);
          
            // Select the longest diameter from two sub trees.
            return max(left, right);
        }
  
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            if (root->left == nullptr && root->right == nullptr) return 0;
            dfs(root);
            return max_diameter;
        }
};
