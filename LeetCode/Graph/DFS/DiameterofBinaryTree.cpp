/* 
 * LeetCode 543 Diameter of Binary Tree
 * Easy
 * Jiawei Wang
 * 2021.8.19
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
    // DP + DFS
    // c <-- (2, 3)
    //  \
    //   a <- (1, 2)
    //    \
    //     b <- (0, 1)
    int diameterOfBinaryTree(TreeNode* root) {
	return dfs(root).first;
    }

private:
    pair<int, int> dfs(TreeNode* root) {
	// (diameter, depth)
	if (root == NULL) {
	    return {0, 0};
	}

	// divide the hole binary tree into pieces of subtrees
	// from bottom to top each tree caculate their diameter recursively
	
	pair<int, int> left = dfs(root->left);
	pair<int, int> right = dfs(root->right);

	int diam = max({left.first, right.first, left.second + right.second}); 
	return {diam ,max(left.second, right.second) + 1};
    }
};
