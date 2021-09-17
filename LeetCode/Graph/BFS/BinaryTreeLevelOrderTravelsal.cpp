/* 
 * LeetCode 102 Binary Tree Level Order Traversal
 * Medium
 * Jiawei Wang
 * 2021.8.6
 */

/* Revision
 * $1 2021.9.17 Jiawei Wang
 * DFS WOW
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
    // #1 BFS
    vector<vector<int>> levelOrder1(TreeNode* root) {
	if (!root) return {};
	vector<vector<int>> ans;
	vector<TreeNode*> Curr, Next;
	Curr.push_back(root);

	while(!Curr.empty()) {  // end situation
	    // This layer
	    ans.push_back({});
	    for (TreeNode* node : Curr) {
		ans.back().push_back(node->val);
		if (node->left) Next.push_back(node->left);
		if (node->right) Next.push_back(node->right);
	    }
	    Curr.swap(Next);
	    Next.clear();
	}
	return ans;
    }

    // #2 DFS
    vector<vector<int>> ans;
    vector<vector<int> > levelOrder2(TreeNode *root) {
	dfs(root, 0);         
	return ans;
    }

private:
    void dfs(TreeNode* r, int dep) {
	if (!r) return;
	while (ans.size() <= dep) ans.push_back({}); // add one more layer
	ans[dep].push_back(r->val);
	dfs(r->left, dep + 1);
	dfs(r->right, dep + 1);
    }
};
