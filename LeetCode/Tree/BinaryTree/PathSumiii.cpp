/*
 *LeetCode 437 Path Sum iii
 *Medium
 *Shuo Feng
 *2021.7.30
 */

/*
 *  On the basic of LeetCode 112：Path Sum ,tarverse all the node in tree as the root node.
 *  
 *  Something to notice:
 * (1) Path like: [ 3,-2, 1,-1] targetSum = 1, include two path.
 * (2) End condition.
 */

#include<iostream>
using namespace std;

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
    int num = 0;
    int pathSum(TreeNode* root, int targetSum) {
        traversal(root, targetSum);
        return num;
    }
    void traversal(TreeNode* root, int targetSum) {
        if (root) {
            Find_Path(root, targetSum);
            traversal(root->left, targetSum);
            traversal(root->right, targetSum);
        }
    }
    void Find_Path(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return;
        else
            targetSum -= root->val;
        if (targetSum == 0) 
            ++num;        
        Find_Path(root->left, targetSum);
        Find_Path(root->right, targetSum);
    }
};
