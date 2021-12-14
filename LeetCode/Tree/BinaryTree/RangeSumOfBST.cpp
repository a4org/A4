/* 
 * LeetCode 938 Range Sum of BST
 * Easy
 * Jiawei Wang
 * 2021.12.14
 */

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
    int rangeSumBST(TreeNode* root, int low, int high) {
	if (root == nullptr) return 0;
	int ret = 0;

	helper(root, low, high, ret);

	return ret;
    }
private:
    void helper(TreeNode* node, int low, int high, int& ret) {
	if (node == nullptr) return;
	int val = node->val;

	if (val < low) {
	    helper(node->right, low, high, ret);
	} else if (val > high) {
	    helper(node->left, low, high, ret);
	} else {
	    helper(node->right, low, high, ret);
	    helper(node->left, low, high, ret);
	    ret += val;
	}
    }
};

