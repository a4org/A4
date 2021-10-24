/*
 * LeetCode 222 Count Complete Tree Nodes
 * Medium
 * Shuo Feng
 * 2021.10.24
 */

#include<iostream>
#include<vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Solution 1: Dfs.
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

/*
 * Better solution:
 */

class Solution {
private:

    // Count depth.
    int countLevel(TreeNode* root) {
        int level = 0;
        while (root != nullptr) {
          
            // Only search left node.
            root = root->left;
            level += 1;
        }
        return level;
    }
  
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_depth = countLevel(root->left);   // Depth of left  sub_tree.
        int right_depth = countLevel(root->right); // Depth of right sub_tree.

        // The depth of left sub_tree = the depth of right sub_tree  -->  left  part is full binary tree.
        if (left_depth == right_depth) {
            // For a n level full binary tree, there are 2ⁿ - 1 nodes, add root node -> 2ⁿ nodes.
            return countNodes(root->right) + (1 << left_depth);
        }
        // The depth of left sub_tree > the depth of right sub_tree  -->  right part is full binary tree.
        else {
            return countNodes(root->left) + (1 << right_depth);
        }
    }
};
