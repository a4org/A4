/*
 * LeetCode 145  Binary Tree Postorder Traversal
 * Easy
 * Jiawei Wang
 * 2021 8.6
 */

/*
 * Postorder Traversal
 * [left, right, root]
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>

using namespace::std;

class Solution {

public:
    vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	postorderTraversal(root, ans);
	return ans;
    }
private:
    void postorderTraversal(TreeNode* root, vector<int>& ans) {
	if (root == nullptr) return;
	postorderTraversal(root->left, ans);
	postorderTraversal(root->right, ans);
    ans.push_back(root->val);
    }

};

