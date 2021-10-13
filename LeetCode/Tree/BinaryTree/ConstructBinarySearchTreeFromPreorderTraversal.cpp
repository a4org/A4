 /* 
 * LeetCode 1008 Construct Binary Search Tree From Preorder Traversal
 * Medium
 * Jiawei Wang
 * 2021.10.13
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
public:
    // #1 Recursive with original function
    // time: O(nlog(n)) 11 ms
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Preorder -> Inorder (Unique)
        // (root -> left -> right) -> (left -> root -> right)
	if (preorder.empty()) {
	    return nullptr;
	}

	int root_value = preorder[0];
	vector<int> smaller, greater;
	// smaller stores the left subtree of curr root
	// greater stores the right subtree of curr root
	for (int i = 1; i < (int) preorder.size(); i++) {
	    if (preorder[i] < root_value) {
		smaller.push_back(preorder[i]);
	    } else {
		greater.push_back(preorder[i]);
	    }

	}
	TreeNode* root = new TreeNode(root_value);
	root->left = bstFromPreorder(smaller);
	root->right = bstFromPreorder(greater);
	return root;
    }

    // #2 Recursive with helper function
    // time: O(n) 3ms
    TreeNode* bstFromPreorder2(vector<int>& preorder) {
	int id = 0;
	return helper(preorder, id, INT_MAX);
    }

private:
    TreeNode* helper(const vector<int>& preorder, int& id, int limit) {
	if (id == (int) preorder.size() || preorder[id] > limit) {
	    // Termination Condition
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

