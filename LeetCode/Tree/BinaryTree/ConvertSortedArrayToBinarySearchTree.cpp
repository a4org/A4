/* 
 * LeetCode 108 Convert Sorted Array to Binary Seach Tree
 * Easy
 * Jiawei Wang
 * 2021.9.17
 */

/* Revision
 * $1 Jiawei Wang 2021.10.13
 */


#include <vector>

using namespace::std;

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
	// Key thought:
	// To mantain the "height balanced" property
	// just need to keep the diff between left subtree nodes number
	// and right subtree nodes number always smaller than 1
	return buildBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* buildBST(const vector<int>& nums, int l, int r) {
	if (l > r) return nullptr;
	int mid = (r+l) / 2; // auto trans to int
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = buildBST(nums, l, mid + l);
	root->right = buildBST(nums, mid + l, r);
	return root;
    }
};
