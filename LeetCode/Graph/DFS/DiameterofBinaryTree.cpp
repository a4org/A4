/* 
 * LeetCode 543 Diameter of Binary Tree
 * Easy
 * Jiawei Wang
 * 2021.8.19
 */

/* Revision:
 * $1 2021.10.11 Jiawei Wang
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
    // #1 DP + DFS
    // c <-- (2, 3)
    //  \
    //   a <- (1, 2)
    //    \
    //     b <- (0, 1)
    int diameterOfBinaryTree(TreeNode* root) {
	return dfs(root).first;
    }

    // #2 DFS
    int diameterOfBinaryTree2(TreeNode* root) {
	ans = 0;
	dfs2(root);
	return ans;
    }

private:
    int ans;
    pair<int, int> dfs(TreeNode* root) {
	// (diameter, depth)
	if (root == NULL) {
	    return {0, 0};
	}

	// divide the hole binary tree into pieces of subtrees
	// from bottom to top each tree caculate their diameter recursively
	
	pair<int, int> left = dfs(root->left);
	pair<int, int> right = dfs(root->right);

	// diam represents the maximum diameter till current node
	int diam = max({left.first, right.first, left.second + right.second}); 
	// depth also the maximum depth till current node
	return {diam ,max(left.second, right.second) + 1};
    }

    int dfs2(TreeNode* root) {
	// return longest side
	if (!root) return -1;
	int l = dfs2(root->left) + 1;
	int r = dfs2(root->right) + 1;
	ans = max(ans, l + r); // update ans
	return max(l, r);
    }
};
