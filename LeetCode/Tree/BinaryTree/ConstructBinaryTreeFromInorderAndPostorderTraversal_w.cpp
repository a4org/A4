/* 
 * LeetCode 105 Construct Binary Tree from Preorder and Inorder Traversal
 * Medium
 * Jiawei Wang
 * 2021.11.21
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

// Inorder  (left, root, right)
// Preorder (node, left, right)
//		*
//	      /   \
//	     *     *
 
class Solution {
public:
    // Unique
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int i = 0;
	return helper(preorder, inorder, i, 0, preorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& id, int left, int right) {
	if (left > right) return nullptr;
	int root = left;
	while(inorder[root] != preorder[id]) root++; // find root
	// because just with preorder, you don't know which one is next layer node 
	// since preorder is the sequence from top to bottom

	// and inorder can tell relationship of left and right with node

	// Key to Understand
	// 1. Find the current root
	// 2. Find the next layer left and right root (by increasing id)
	id++;

	TreeNode* newNode = new TreeNode(inorder[root]);
	newNode->left = helper(preorder, inorder, id, left, root-1);
	newNode->right = helper(preorder, inorder, id, root+1, right);
	return newNode;
    }
};
