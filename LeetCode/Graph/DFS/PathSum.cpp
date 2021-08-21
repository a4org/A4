/* 
 * LeetCode 112 Path Sum
 * Easy
 * Jiawei Wang
 * 2021.8.21
 */

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        else 
            targetSum -= root->val;
       
        if (targetSum == 0 && (root->left == nullptr && root->right ==nullptr))
            return true;         
 
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);           
    }                                                        
};



