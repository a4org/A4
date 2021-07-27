/*
 * LeetCode 114 Flatten Binary Tree to Linked List
 * Medium
 * Jiawei Wang
 * 2021 7.27
 */

#include <iostream>

using namespace::std;

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
    void flatten(TreeNode* root) {
	// Two boundary conditions
	if (root == NULL) return;
	if (root->left == NULL) {
	    flatten(root->right);
	    return;
	}

	TreeNode* h1 = root->left;
	TreeNode* h2 = root->right;

	flatten(root->left);
	flatten(root->right);

	root->right = h1;
	root->left = NULL;

	while (h1->right!=NULL) {
	    h1 = h1->right;
	}
	h1->right = h2;
    }
};

