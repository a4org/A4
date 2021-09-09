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
	unordered_map<TreeNode*, int> flag0; // flag0[TreeNode* Node] := maximum amount of money if we can't choose current node 
	unordered_map<TreeNode*, int> flag1; // from Node to the leaf node of the tree

	int rob2(TreeNode* root) {
	    return DFS2(root, 1);
	}

	int DFS2(TreeNode* node, int flag) { 
	    if (node == NULL) return 0;

	    if (flag == 1 && flag1.find(node) != flag1.end()) {
		return flag1[node];
	    }
	    if (flag == 0 && flag0.find(node) != flag0.end()) {
		return flag0[node];
	    }

	    int ret; // final ans
	    if (flag == 0) {
		// cannot choose this node
		ret = DFS2(node->left, 1) + DFS2(node->right, 1);
	    } else {
		// can choose this node
		int option1 = node->val + DFS2(node->left, 0) + DFS2(node->right, 0); // choose this node
		int option2 = DFS2(node->left, 1) + DFS2(node->right, 1); // do not choose this node
		ret = max(option1, option2);
	    }

	    if (flag == 1) flag1[node] = ret;
	    if (flag == 0) flag0[node] = ret;

	    return ret;
	}
};

