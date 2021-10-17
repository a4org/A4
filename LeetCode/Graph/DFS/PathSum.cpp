/* 
 * LeetCode 112 Path Sum
 * Easy
 * Jiawei Wang
 * 2021.8.21
 */

/* Revision
 * $1 2021.9.28 Jiawei Wang
 * Back Tracking (When get the leaf node then you can judge)
 * $2 2021.10.17 Jiawei Wang
 */

#include <stack>
#include <iostream>

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
    // #1 DFS (More Suitable)
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        else 
            targetSum -= root->val;
       
        if (targetSum == 0 && (root->left == nullptr && root->right == nullptr))
            return true;         
 
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);           
    }                                                        

    // #2 BFS
    bool hasPathSum2(TreeNode* root, int targetSum) {
	if (root == nullptr) return false;
	// two stack store corresponding root and value respectively
	stack<TreeNode*> path;
	stack<int> sub;
	path.push(root);
	sub.push(root->val);

	while(!path.empty()) {
	    TreeNode* temp = path.top(); path.pop();
	    int tempVal = sub.top(); sub.pop();
	    if (temp->left == nullptr && temp->right == nullptr) {
		if (tempVal == targetSum) return true; // Termination Condition
	    } else {
		if (temp->left != nullptr) {
		    path.push(temp->left);
		    sub.push(temp->left->val + tempVal);
		}

		if (temp->right != nullptr) {
		    path.push(temp->right);
		    sub.push(temp->right->val + tempVal);
		}
	    }

	}
	return false;
    }
};



