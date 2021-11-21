/* 
 * LeetCode 106 Construct Binary Tree from Inorder and Postorder Traversal
 * Medium
 * Jiawei Wang
 * 2021.11.21
 */

#include <vector>

using namespace::std;

// Postorder (left, right, root)  -> tells the left and right property
// Inorder   (left, root, right)  -> tells the left and node and right property

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2) {
	if (i1 > i2 || p1 > p2) return nullptr;

	TreeNode* newNode = new TreeNode(postorder[p2]); // root

	int root = i1;

	while (postorder[p2] != inorder[root]) root++;

	// Key to Understand:
	// next root is p1+root-i1-1(left) and p2-1(right) (root and its right)
	// (root-i1) -> ++ times -> how many nodes on the left
	// since in inorder, left, root, right, the '++' times to root represents the num of left (subtree)
	newNode->left = helper(inorder, i1, root-1, postorder, p1, p1+root-i1-1); 
	newNode->right = helper(inorder, root+1, i2, postorder, p1+root-i1, p2-1);

	return newNode;
    }
};

