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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        vector<TreeNode*> Curr;
        vector<TreeNode*> Next;
        int depth = 0;
        Curr.push_back(root);
        
        while (!Curr.empty()) { // still have child node
            depth++;
            for (TreeNode* node : Curr) {
                if (node->left) Next.push_back(node->left);
                if (node->right) Next.push_back(node->right);
            }
            Curr.swap(Next);
            Next.clear();
        }
        return depth;
    }
    // DFS
    // Key: left and right big subtree (itearation)
    int maxDepth2(TreeNode* root) {
	return root == NULL? 0 : max(maxDepth2(root->left), maxDepth2(root->right));
    }

};
