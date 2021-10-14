/* 
 * LeetCode 98 Validate Binary Seach Tree
 * Easy
 * Jiawei Wang
 * 2021.9.12
 */

/* Revision
 * $1 2021.10.13 Jiawei Wang
 * grandpa (LeetCode 1008)
 */

#include <vector>
#include <stack>
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

/* NOTICE:
 * Since Both BFS and DFS were traversal in different sequence
 * We ususally can solve a traversal problem with these two methods
 */
 
class Solution {
public:
    // DFS #1 Range 
    // Key: Just focus on the "Sub Trees"
    // Thought Wisely!
    //         o
    //      /     \
    //     .      .
    //    /_\    / \
    //          /___\
    //    
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
	// check whether the subtree with root is a valid BST
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST1(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }



    // BFS #1 Range
    // key: focus on each "root"
    stack<TreeNode*> stk, lower_limits, upper_limits;
    void update(TreeNode* root, TreeNode* low, TreeNode* high) {
	stk.push(root);
	lower_limits.push(low);
	upper_limits.push(high);
    }

    bool isValidBST2(TreeNode* root) {
	TreeNode* low = nullptr;
	TreeNode* high = nullptr;
	update(root, low, high);

	while (!stk.empty()) {
	    root = stk.top();
	    stk.pop();
	    low = lower_limits.top();
	    lower_limits.pop();
	    high = upper_limits.top();
	    upper_limits.pop();

	    if (root == nullptr) continue; // just skip some nullptr (tree may not full in some depth)

	    TreeNode* val_node = root;
	    if (low != nullptr && val_node->val <= low->val) return false;
	    if (high != nullptr && val_node->val >= high->val) return false;

	    // valid "root" check its child nodes
	    // same sequence in each stack
	    update(root->right, val_node, high);
	    update(root->left, low, val_node);
	}
	// pass all tests
	return true;
    }


    // DFS #2 Recursive Inorder Traversal
    TreeNode* prev = nullptr;
    bool isValidBST3(TreeNode* root) {
	return inorder(root);
    }

    bool inorder(TreeNode* root) {
	// "Subtree"
	if (root == nullptr) {
	    return true;
	} 
	if (!inorder(root->left)) {
	    // left subtree
	    return false;
	}
	if (prev != nullptr && root->val <= prev->val) {
	    return false;
	}
	prev = root;
	return inorder(root->right); // right subtree
    }


    // BFS #2 Iterative Inorder Traversal
    bool isValidBST4(TreeNode* root) {
	stack<TreeNode*> stk;
	TreeNode* prv = nullptr;

	while (!stk.empty() || root != nullptr) { 
	    while (root != nullptr) {
		stk.push(root);
		root = root->left;
		// all left roots
	    }
	    root = stk.top();
	    stk.pop();

	    if (prv != nullptr && root->val <= prv->val) {
		return false;
	    }
	    prv = root;
	    root = root->right;
	}
	return true;
    }

};
