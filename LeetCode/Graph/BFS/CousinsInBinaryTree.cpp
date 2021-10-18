/* 
 * LeetCode 993 Cousins In Binary Tree
 * Easy
 * Jiawei Wang
 * 2021.10.18
 */


#include <vector>
#include <unordered_map>

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
    // BFS 0ms
    bool isCousins1(TreeNode* root, int x, int y) {
        // Two nodes of a binary tree are cousins if they have the same depth with different parents.
        vector<TreeNode*> Curr, Next;
        Curr.push_back(root);
        
        TreeNode* parent = nullptr; // record the parent
        
        while (!Curr.empty()) {
            for (auto node : Curr) {
                // This layer nodes elements
                if (node->left) {
                    if (node->left->val == x || node->left->val == y) {
                        if (parent) {
                            // there is already a element
                           if (parent->val != node->val) return true;
                           else return false;
                        }
                        parent = node;
                    }
                    Next.push_back(node->left);
                } 
                
                if (node->right) {
                    if (node->right->val == x || node->right->val == y) {
                        if (parent != nullptr) {
                            if (parent->val != node->val) return true;
                            else {
                                return false;
                            }
                        }
                        parent = node;
                    }
                    Next.push_back(node->right);
                }
                
            }
            if (parent) return false;
            Curr.swap(Next);
            Next.clear();
        }
        return false;
    }

    // DFS
    TreeNode* px;
    TreeNode* py;
    int depthx, depthy;
    bool isCousins2(TreeNode* root, int x, int y)  {
	// only appeared once

	helper(root, x, y, nullptr, 0);

	return px && py && px->val == py->val && depthx != depthy;

    }

private:
    void helper(TreeNode* root, int x, int y, TreeNode* parent, int depth) {
	if (root == nullptr) {
	    // Termination Condition
	    return;
	}

	if (root->val == x) {
	    px = parent;
	    depthx = depth;
	}

	if (root->val == y) {
	    py = parent;
	    depthy = depth;
	}

	helper(root->left, x, y, root, depth+1);
	helper(root->right, x, y, root, depth+1);
    }

}; 
