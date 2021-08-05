/*
 * LeetCode 144  Binary Tree Preorder Traversal
 * Medium
 * Jiawei Wang
 * 2021 7.19
 */

/*
 * Preorder
 * [root, left, right]
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
	vector<int> results;
	stack<TreeNode*> Stack;

	while (root != NULL || !Stack.empty()) {
	    if (root != NULL) {
		Stack.push(root);
		results.push_back(root->val);
		root = root->left;
	    } else {
		root = Stack.top();
		Stack.pop();
		root = root->right;
	    }
	}
	return results;
    }
};
