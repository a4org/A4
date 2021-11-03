/*
 * LeetCode 62 Unique Paths
 * Medium
 * Jiawei Wang
 * 2021 8.13
 */

/*
 * Revision
 * $1 2021.11.2 Jiawei Wang
 * either down or right
 */


#include <vector>

using namespace::std;


class Solution {
public:
    // DP
    int uniquePaths(int m, int n) {
	int dp[m][n];  // dp table, each node represents number of ways when arrived at curr

	for (int i = 0; i < m; i++) dp[i][0] = 1;
	for (int j = 0; j < n; j++) dp[0][j] = 1;

	for (int i = 1; i < m; i++) {
	    for (int j = 1; j < n; j++) {
		// reach this point from both left or top
		dp[i][j] = dp[i-1][j] + dp[i][j-1];
	    }
	}
	return dp[m-1][n-1];
    }
};
