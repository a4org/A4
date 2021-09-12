/* 
 * LeetCode 104 Maximum Depth of Binary Tree
 * Easy
 * Jiawei Wang
 * 2021.9.12
 */

// BFS and DFS search -> Traverse the tree

// Definition for a binary tree node.

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
    // BFS
    int maxDepth1(TreeNode* root) {
	vector<TreeNode*> Curr, Next;
	int depth = 0;

	while (Curr.empty()) {
	    depth++;
	    for (auto node : Curr) 
		// each child node in this layer
		Next.push_back(node);

	    Curr.swap(Next);
	    Curr.clear();
	}
	return depth;
    }

    // DFS
    // Key: left and right big subtree (itearation)
    int maxDepth2(TreeNode* root) {
	return root == NULL? 0 : max(maxDepth2(root->left), maxDepth2(root->right));
    }

}
