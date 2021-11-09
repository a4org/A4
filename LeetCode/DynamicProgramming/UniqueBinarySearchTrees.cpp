/*
 * LeetCode 96 Unique Binary Search Trees
 * Medium
 * Jiawei Wang
 * 2021 8.13
 */

/* Revision
 * $1 2021.11.8 Jiawei Wang
 */

#include <vector>

/* 
 * DP
 * Since it is a binary search tree
 * while thinking, there must be a very simple way to solve this problem
 * according to the principle of building a binary tree
 */

using namespace::std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
	// i represents the value of index number
      for(int j = 0; j < i; j++)
	  // j represents the left subtree size (smaller than i)
        dp[i] += dp[j] * dp[i - j - 1];  // left possible cases * right possible cases
    return dp[n];
  }
};

