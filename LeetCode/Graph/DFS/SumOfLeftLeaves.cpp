/*
 * LeetCode 404 Sum Of Left Leaves
 * Easy
 * Shuo Feng
 * 2021.11.4
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
 * Solution: Dfs.
 *   Dfs the tree, use 'place' to stand left node('L') or right node('R'), by this way we can judge whether the node is left leaves,
 */

class Solution {
private:
    // char place:  'L' : left node.
    //              'R' : right node.
    void helper(TreeNode* root, int& sum, char place) {
        if (root == nullptr)
            return;

        // Meet leaves.
        if (root->left == nullptr && root->right == nullptr) {
            if (place == 'L') {
                sum += root->val;
            }
            return;
        }

        if (root->left != nullptr) {
            helper(root->left, sum, 'L');
        }

        if (root->right != nullptr) {
            helper(root->right, sum, 'R');
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, '0');
        return sum;
    }
};
