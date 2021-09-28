/* 
 * LeetCode 437 Path Sum iii
 * Medium
 * Jiawei Wang
 * 2021.8.23
 */

/* Revision
 * $1 2021.9.28 Jiawei Wang 
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
    vector<int> dp; 
    // Key: understand the vector dp 
    // dp[i] only store the sum from 0 to ith elements
    int currSum = 0;
    int num = 0;  // return value

    // #1 DP + DFS
    int pathSum(TreeNode* root, int targetSum) {
	dfs(root, targetSum);
	return num;
    }

    void dfs(TreeNode* root, int targetSum) {
	if (root == nullptr) return;
	else {
	    currSum += root->val;
	    dp.push_back(currSum);
	}

	if (currSum == targetSum) num++;
	for (int j = 0; j < dp.size(); j++) { // all subpath
	    int i = dp.size() - 1; // ith dp (curr)
	    int tmp = dp[i] - dp[j];
	    if (tmp == targetSum && i != j) {
		// avoid 0
		num++;
	    }
	}

	dfs(root->left, targetSum);
	dfs(root->right, targetSum);

	// back to its parent nodes
	// guarantee the dp property (Understand)
	currSum -= root->val;
	dp.pop_back();
    }

    int num2 = 0; // Path num.
    // #2 DFS
    int pathSum2(TreeNode* root, int targetSum) {
        traversal(root, targetSum);
        return num2;
    }
    
    // For each node, Treat it as the starting node and then check the path after it.
    void traversal(TreeNode* root, int targetSum) {
	// traversal just for iteration
        if (root) {
            Find_Path(root, targetSum);
            traversal(root->left, targetSum);
            traversal(root->right, targetSum);
        }
    }
    void Find_Path(TreeNode* root, int targetSum) {
	// set root as the starting node, and then explore all pathes after it
        if (root == nullptr)
            return;
        else
            targetSum -= root->val;
        if (targetSum == 0) 
            ++num2;        
        Find_Path(root->left, targetSum);
        Find_Path(root->right, targetSum);
    }
};
