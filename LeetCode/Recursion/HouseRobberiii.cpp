/*
 * LeetCode 337  House Robber iii
 * Medium
 * Jiawei Wang
 * 2021 7.25
 */

/* Revision
 * $1 2021.9.9 Jiawei Wang
 * For each house, the thief can choose rob it or not
 * To understand why #2 uses Hash ->  Why #1 has many repetitive dfs? 
 * Cannot choose this node (flag == 0) with can but do not choose this node (flag == 1)
 *
 * $2 2021.11.9 Jiawei Wang
 * Using global variable and parameter ref seems like have the same speed...
 */

/* #1 Normal Recursive DFS
 * Correct but exceed the time limit
 * Reason: Too many repetitive dfs were made
 *
 * #2 Recursive DFS with Hash
 * Like #1 but uses two hash map to store all values
 */

struct TreeNode {
    // Definition of a binary tree node
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#include <vector>
#include <unordered_map>

using namespace::std;

class Solution {
    public:
	// #1 Normal Recursive DFS
	// TLE 
	int rob1(TreeNode* root) {
	    return DFS1(root, 1);
	}

	int DFS1(TreeNode* node, int flag) { 
	    if (node == NULL) return 0;

	    if (flag == 0) {
		// cannot choose this node
		return DFS1(node->left, 1) + DFS1(node->right, 1);
	    } else {
		// can choose this node
		int option1 = node->val + DFS1(node->left, 0) + DFS1(node->right, 0); // choose this node
		int option2 = DFS1(node->left, 1) + DFS1(node->right, 1); // do not choose this node
		return max(option1, option2);
	    }
	}


	// #2 Recursive DFS with Hash
	int rob(TreeNode* root) {
	    unordered_map<TreeNode*, int> cann;
	    unordered_map<TreeNode*, int> cant;
	    return helper(root, 1, cann, cant);
	}

private:
	int helper(TreeNode* node, int can, unordered_map<TreeNode*, int>& cann, unordered_map<TreeNode*, int>& cant) {
	    if (node == nullptr) return 0;

	    if (can && cann.find(node) != cann.end()) {
		return cann[node];
	    }

	    if (!can && cant.find(node) != cann.end()) {
		return cant[node];
	    }

	    int ret = 0;
	    if (can) {
		int option1 = node->val + helper(node->left, 0, cann, cant) + helper(node->right, 0, cann, cant);
		int option2 = helper(node->left, 1, cann, cant) + helper(node->right, 1, cann, cant);
		ret = max(option1, option2);
		cann[node] = ret;
	    } else {
		ret = helper(node->left, 1, cann, cant) + helper(node->right, 1, cann, cant);
		cant[node] = ret;
	    }
	    return ret;
	}
};

