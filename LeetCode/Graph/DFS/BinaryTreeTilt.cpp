/* 
 * LeetCode 563 Binary Tree Tilt
 * Easy
 * Jiawei Wang
 * 2021 12.08
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
    int findTilt(TreeNode* root) {
        // DFS
	int ret = 0;

	if (root == nullptr) return 0;

	helper(root, ret);

	return ret;
    }

private: 
    int helper(TreeNode* node, int &ret) {
	int left = (node->left ? helper(node->left, ret) : 0);
	int right = (node->right ? helper(node->right, ret) : 0);

	ret += (left - right > 0) ? left - right : right - left;
	return left + right + node->val;
    }

};
