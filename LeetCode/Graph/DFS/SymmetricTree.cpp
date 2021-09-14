/* 
 * LeetCode 101 Symmetric Tree
 * Easy
 * Jiawei Wang
 * 2021.9.14
 */

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

class Solution {
private:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
	if (!root1 && !root2) return true;  // root1 == nullptr == root2
	if (!root1 || !root2) return false; // one of root1 and root2 is a nullptr
	return root1->val == root2->val 
           && isMirror(root1->right, root2->left) 
           && isMirror(root1->left, root2->right);
  }

public:
    // DFS
    // iteration
    bool isSymmetric1(TreeNode* root) {
	return isMirror(root, root);
    }

    // BFS
    bool isSymmetric2(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        stack<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.top();
            q1.pop();
            right = q2.top();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
		// One of the left node and right node is nullptr
                return false;
            if (left->val != right->val)
                return false;
	    // left->left -- right->right
	    // left->right -- right->left
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }

};
