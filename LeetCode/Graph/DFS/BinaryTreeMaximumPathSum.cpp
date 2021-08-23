/* 
 * LeetCode 124 Binary Tree Maximum Path Sum
 * Hard
 * Jiawei Wang
 * 2021.8.23
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
    // maximum subarray (53) + Longest path (687)
    // Kadane's algorithm + DFS
    int maxPathSum(TreeNode* root) {
	// Treat each subtree as a whole tree (in each node)
	int ans = INT_MIN;
	dfs(root, ans);
	return ans;
    }

    int dfs(TreeNode* root, int& ans) {
	if (!root) return 0;
	// from bottom to top
	int l = max(0, dfs(root->left, ans));  // maximum length of left whole subtree
	int r = max(0, dfs(root->right, ans)); // maximum length of right whole subtree

	int sum = l + r + root->val;
	ans = max(ans, sum);
	return max(l, r) + root->val; // like 687 we only can return one side
    }
};
