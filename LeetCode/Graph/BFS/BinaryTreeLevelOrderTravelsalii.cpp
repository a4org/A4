/* 
 * LeetCode 107 Binary Tree Level Order Traversal ii
 * Medium
 * Jiawei Wang
 * 2021.8.9
 */

#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
	if (!root) return {};
	vector<vector<int>> ans;
	vector<TreeNode*> Curr, Next;
	Curr.push_back(root);

	while (!Curr.empty()) {
	    ans.push_back({});
	    for (TreeNode* node : Curr) {
		ans.back().push_back(node->val);
		if (node->left) Next.push_back(node->left);
		if (node->right) Next.push_back(node->right);
	    }
	    Curr.swap(Next);
	    Next.clear();
	}
	reverse(ans.begin(), ans.end());
	return ans;
    }
};

