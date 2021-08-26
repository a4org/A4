/*
 * LeetCode 230 Kth Smallest Element in a BST
 * Medium
 * Shuo Feng
 * 2021.8.26
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
 * Solution 1: Dfs
 *   Inorder traverse the tree , due to the BST the number we get is ascending, only return the kth number.
 *
 *   Something to notice: to count we have to use a variate outside of traversal( avoid recall ).
 */

class Solution {
public:
    int num = 0;
    int kk;
    int kthSmallest(TreeNode* root, int k) {
        kk = k;
        dfs(root);
        return num;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;

        dfs(root->left);
        if (--kk == 0) {
            num = root->val;
            return;
        }
        dfs(root->right);
    }
};


/*
 * Solution 2:
 *   Same as solution 1, but use a array to save the result of traversal, the " k- 1 " number is the one we need.
 */

class Solution {
public:
    vector<int> nums;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return nums[k - 1];
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};
