/*
 * LeetCode T113 PathSumii
 * Medium
 * Shuo Feng
 * 2021.7.29
 * Last edited at 2021.8.30
 */

/*
 *  Solution:
 *   On the basic of LeetCode T112, to get the path, we should only record the path we have passed by
 *  and check it.
 *
 *   about Path. pop_back() in line 51:
 *   For a node, if we fail to get a result we want on it`s left_subtree and right_subtree,including itself,
 *  we should use a 'pop_back()' to delete it`s value in the Path （From bottom to top）.
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

class Solution {
public:

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> Path_integration;  // Vector to record the tree that we need
        vector<int> Path;                      // Record the tree which is traversing
        Find_Path(root, targetSum, Path, Path_integration);

        return Path_integration;
    }

    void Find_Path(TreeNode* root, int targetSum, vector<int>& Path, vector<vector<int>>& Path_integration) {
        if (root == nullptr)
            return;
        else {
            targetSum -= root->val;  // Condition: root != nullptr
            Path.push_back(root->val);
        }
        // End condition.
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr)
            Path_integration.push_back(Path);

        Find_Path(root->left, targetSum, Path, Path_integration);
        Find_Path(root->right, targetSum, Path, Path_integration);
        Path.pop_back();
    }
};
