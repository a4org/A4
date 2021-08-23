/* 
 * LeetCode 437 Path Sum iii
 * Medium
 * Jiawei Wang
 * 2021.8.23
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
    vector<int> dp; // dp[i] represents the sum from 0 to i
    int currSum = 0;
    int num = 0;  // return
    // DP + DFS
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
	for (int j = 0; j < dp.size(); j++) {
	    int i = dp.size() - 1;
	    int tmp = dp[i] - dp[j];
	    if (tmp == targetSum && i != j) {
		// there may have 0
		num++;
	    }
	}

	dfs(root->left, targetSum);
	dfs(root->right, targetSum);
	currSum -= root->val;
	dp.pop_back();
    }
};

