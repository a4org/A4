/* 
 * LeetCode 222 Count Complete Tree Node
 * Medium
 * Jiawei Wang
 * 2021.10.24
 */

#include <vector>
#include <cmath>

using namespace::std;


// full binary tree -> every node other than the leaves as two children
// complete binary tree -> every level except possibly the last, is completely filled
// and all nodes are as far left as possible

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
    // #1 Google hasK Interview Question (Binary Search)
    int countNodes(TreeNode* root) {
	int h = 0;
	TreeNode* node = root;

	while (node != NULL) {
	    // caculate the complete binary tree height
	    h++;
	    node = node->left;
	}

	// binary search at the last layer
	int low = pow(2, h-1);
	int hi = pow(2, h) - 1;

	while (low < hi) {
	    int mid = low + (hi - low + 1) / 2;
	    // every time using binary search
	    // try low = 0, hi = 1 for checking
	    if (hasK(root, mid)) {
		// we has that node
		low = mid;
	    } else {
		hi = mid-1;
	    }
	}
	return low;
    }

private:
    bool hasK(TreeNode* root, int K) {
	// has node at position K
	vector<int> path;
	while (K > 0) {
	    path.push_back(K);
	    K = K / 2;
	}

	for (int i = path.size()-1; i >= 0; i--) {
	    if (root == NULL) {
		// Termination Condition
		return false;
	    }
	    if (i == 0) {
		// current root isn't null
		// we went through our path
		return true;
	    }

	    if (path[i-1] == path[i]*2) {
		root = root->left;
	    } else {
		root = root->right;
	    }
	}

	return false;
    }

public:
    // #2 Recursion
    // O(logn * logn)
    int countNodes2(TreeNode* root) {
	// return No. of nodes of current root
	// Key:
	// For each node in a complete binary tree (except leaf nodes):
	// at least one of its child tree (left or right) is complete
	if (root == NULL) {
	    return 0;
	}

	int h1 = findLeftDepth(root->left);
	int h2 = findRightDepth(root->left);
	int h3 = findLeftDepth(root->right);

	if (h1 == h2) {
	    // left subtree is a full binary tree
	    return pow(2, h1) + countNodes(root->right); // + right count
	} else {
	    // right subtree is a full binary tree
	    return pow(2, h3) + countNodes(root->left);  // + left count
	}
    }

private:
    int findLeftDepth(TreeNode* root) {
	int h = 0;
	while (root != NULL) {
	    h++;
	    root = root->left;
	}
	return h;
    }

    int findRightDepth(TreeNode* root) {
	int h = 0;
	while (root != NULL) {
	    h++;
	    root = root->right;
	}
	return h;
    }

};
