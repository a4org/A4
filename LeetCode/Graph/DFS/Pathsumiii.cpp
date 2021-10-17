/* 
 * LeetCode 437 Path Sum iii
 * Medium
 * Jiawei Wang
 * 2021.8.23
 */

/* Revision
 * $1 2021.9.28 Jiawei Wang 
 * $2 2021.10.17 Jiawei Wang 
 */

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
    // avoid using global varibles (store in global memory)
    // vs local variables (store in register or stack(L1 cache))
    //#1  DP (number of roots) + DFS
    int pathSum1(TreeNode* root, int targetSum) {
        vector<int> dp; // dp[i] => the target sum from root to index i in this path (backtracking dp)
        int ret = 0;
        int currentSum = 0;
        
        helper(dp, root, targetSum, currentSum, ret);
        
        return ret;
    }
private:
    void helper(vector<int>& dp, TreeNode* root, int targetSum, int& currentSum, int& ret) {
        if (root == nullptr) return;
        
        currentSum += root->val;
        dp.push_back(currentSum);
        
        // each node can only be treat as "leaf node" once
        for (int i = 0; i < dp.size(); i++) {
            int j = dp.size()-1; // curr left node;
            if (dp[j] - dp[i] == targetSum && i != j) ret++;
        }
        
        if (currentSum == targetSum) ret++;
        
        helper(dp, root->left, targetSum, currentSum, ret);
        helper(dp, root->right, targetSum, currentSum, ret);
        
        currentSum -= root->val;
        dp.pop_back();
    }

public:
    // #2 DFS
    int pathSum2(TreeNode* root, int targetSum) {
	int num2 = 0;
        traversal(root, targetSum, num2);
        return num2;
    }
    
    // For each node, Treat it as the starting node and then check the path after it.
    void traversal(TreeNode* root, int targetSum, int& num2) {
	// traversal just for iteration
        if (root) {
            Find_Path(root, targetSum, num2);
            traversal(root->left, targetSum, num2);
            traversal(root->right, targetSum, num2);
        }
    }
    void Find_Path(TreeNode* root, int targetSum, int& num2) {
	// set root as the starting node, and then explore all pathes after it one by one
        if (root == nullptr)
            return;
        else
            targetSum -= root->val;
        if (targetSum == 0) 
            ++num2;        
        Find_Path(root->left, targetSum, num2);
        Find_Path(root->right, targetSum, num2);
    }
};
