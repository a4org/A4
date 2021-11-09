/*
 * LeetCode 931 Minimum Fallin Path Sum
 * Medium
 * Jiawei Wang
 * 2021 11.7
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
	// the ith layer only depends on the i-1 layer
	// DP Basic i
	int n = matrix.size();
	if (n == 0) return 0;
	int m = matrix[0].size();

	vector<int> dp(matrix[0].begin(), matrix[0].end());
	vector<int> old_dp;
	for (int i = 1; i < n; i++) {
	    // start from second layer
	    old_dp = dp;
	    for (int j = 0; j < m; j++) {
		// if you want to choose matrix[i][j]
		if (j == 0) dp[j] = min(old_dp[j], old_dp[j+1]) + matrix[i][j];
		else if (j == m-1) dp[j] = min(old_dp[j-1], old_dp[j]) + matrix[i][j];
		else dp[j] = min(old_dp[j-1], min(old_dp[j], old_dp[j+1])) + matrix[i][j];
	    }
	}

	int ret = INT_MAX / 2;
	for (int i = 0; i < m; i++) {
	    if (ret > dp[i]) ret = dp[i];
	}

	return ret;
    }
};

