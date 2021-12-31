/*
 * LeetCode 1026 Maximum Difference Between Node and Ancestor
 * Medium
 * Jiawei Wang
 * 2021.12.31
 */

#include <vector>
#include <cstdlib>

using namespace std;

// Definition for a binary tree node.
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
    int maxAncestorDiff(TreeNode* root) {
	// DFS
	// for each node, compare them with its min or max child node
	int ret = 0;  // final answer

	helper(root, ret);

	return ret;
    }

private:
    pair<int, int> helper(TreeNode* node, int& ret) {
	int val = node->val;
	int minc = val;
	int maxc = val;
	if (node->left == nullptr && node->right == nullptr) {
	    // Termination Condition
	    minc = maxc = val;
	    return make_pair(minc, maxc);
	}

	if (node->left && node->right) { 
	    pair<int, int> lminmax = helper(node->left, ret);
	    pair<int, int> rminmax = helper(node->right, ret);

	    minc = min(minc, min(lminmax.first, rminmax.first));
	    maxc = max(maxc, max(lminmax.second, rminmax.second));

	} else {
	    // Speed up
	    if (node->left) {
		pair<int, int> lminmax = helper(node->left, ret);
		minc = min(minc, lminmax.first);
		maxc = max(maxc, lminmax.second);
	    }

	    else if (node->right) {
		pair<int, int> rminmax = helper(node->right, ret);
		minc = min(minc, rminmax.first);
		maxc = max(maxc, rminmax.second);
	    }
	}

	// Treat current node as "root"
	ret = max(ret, max(abs(val - minc), abs(val - maxc)));

	return make_pair(minc, maxc);
    }
};


