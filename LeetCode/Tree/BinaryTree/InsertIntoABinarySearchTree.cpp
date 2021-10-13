 /* 
 * LeetCode 701 Insert Into a Binary Search Tree
 * Medium
 * Jiawei Wang
 * 2021.10.13
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // termination condition
        if (root == nullptr) {
            // add it to the leaf
            root = new TreeNode(val);
        }
        else if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
