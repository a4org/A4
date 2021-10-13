/*
 * LeetCode 894 All Possible Full Binary Search Trees
 * Medium
 * Jiawei Wang
 * 2021 10.13
 */

#include <vector>

using namespace::std;

// Definition for a binary tree node.
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
  vector<TreeNode*> allPossibleFBT(int n) {
      if (n % 2 == 0) {
	  // full binary tree
	  return {};
      }
      vector<vector<TreeNode*>> dp(n+1);
      dp[1] = {new TreeNode(0)};
      for (int i = 3; i <= n; i += 2) {
	  // i stands for the size of subtree
	  for (int j = 1; j < i; j += 2) {
	      int rm = i - j - 1; // remain
	      for (const auto& l : dp[j]) {
		  for (const auto& r : dp[rm]) {
		      auto root = new TreeNode(0);
		      root->left = l;
		      root->right = r;
		      dp[i].push_back(root);
		  }
	      }
	  }
      }
      return dp[n];
  }
};
