/* 
 * LeetCode 102 Binary Tree Level Order Traversal
 * Medium
 * Jiawei Wang
 * 2021.8.6
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

	while(!Curr.empty()) {
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
    vector<vector<int> > levelOrder2(TreeNode *root) {
	vector<vector<int>> ans;
	function<void(TreeNode*, int)> dfs = [&](TreeNode* r, int d) {
	  if (!r) return;
	  while (ans.size() <= d) ans.push_back({});      
	  ans[d].push_back(r->val);      
	  dfs(r->left, d + 1);
	  dfs(r->right, d + 1);
	};
	dfs(root, 0);         
	return ans;
    }
};
