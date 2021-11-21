/* 
 * LeetCode 1008 Construct Binary Search Tree From Preorder Traversal
 * Medium
 * Jiawei Wang
 * 2021.10.13 (:)
 */

/* 
 * Revision
 * $1 2021.11.21 Jiawei Wang
 */


#include <vector>

using namespace::std;

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
    // Preorder = (left, right, root)
public:
    // #1 Intuition (left and right subtree) (O(N^2) (non-balanced tree))
    TreeNode* bstFromPreorder(vector<int>& preorder) {
	int n = preorder.size();
	if (!n) return nullptr;

	int root_value = preorder[0];
	vector<int> smaller, greater;

	for (int i = 1; i < n; i++) { 
	    int val = preorder[i];
	    if (val < root_value) {
		smaller.push_back(val);
	    } else {
		greater.push_back(val);
	    }
	}
	TreeNode* root = new TreeNode(root_value);
	root->left =  bstFromPreorder(smaller);
	root->right = bstFromPreorder(greater);
	return root;
    }


    // #2 O(N)
    TreeNode* bstFromPreorderii(vector<int>& preorder) {
	int i = 0;
	return helper(preorder, i, INT_MAX);
    }
private:
    TreeNode* helper(const vector<int>& preorder, int& id, int limit) {
	if (id == (int) preorder.size() || preorder[id] > limit) {
	    return nullptr;
	}
	int root_value = preorder[id];
	TreeNode* root = new TreeNode(root_value);
	id++;
	root->left = helper(preorder, id, root_value);
	root->right = helper(preorder, id, limit);
	return root;
    }
};
