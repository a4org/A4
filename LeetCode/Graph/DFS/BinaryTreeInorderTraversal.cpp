/* 
 * LeetCode 94 Binary Tree Inorder Traversal
 * Easy
 * Jiawei Wang
 * 2021.8.5
 *
 */

/* Revision
 * $1 2021.9.13 Jiawei Wang
 */

/* 
 * DFS Search
 * [left, root, right] (inorder)
 */

#include <vector>
#include <stack>

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
    // #1 DFS Recursion
    vector<int> inorderTraversal1(TreeNode* root) {
	vector<int> ans;
	inorderTraversal(root, ans);
	return ans;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
	// Subtree
	if (root == nullptr) return;
	inorderTraversal(root->left, ans);
	ans.push_back(root->val);
	inorderTraversal(root->right, ans);
    }

    // #2 BFS Iteration
    vector<int> inorderTraversal2(TreeNode* root) {
	vector<int> ans;
	stack<TreeNode*> stk;

	while (!stk.empty() || root != nullptr) {
	    while (root != nullptr) {
		stk.push(root);
		root = root->left;
	    }
	    root = stk.top();
	    stk.pop();
	    ans.push_back(root->val);
	    root = root->right;
	}
	return ans;
    }

};
