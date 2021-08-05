/* 
 * LeetCode 94 Binary Tree Inorder Traversal
 * Easy
 * Jiawei Wang
 * 2021.8.5
 *
 */

/* 
 * DFS Search
 * [left, root, right] (inorder)
 */

#include <vector>

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
    vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	inorderTraversal(root, ans);
	return ans;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
	if (root == nullptr) return;
	inorderTraversal(root->left, ans);
	ans.push_back(root->val);
	inorderTraversal(root->right, ans);
    }
};
