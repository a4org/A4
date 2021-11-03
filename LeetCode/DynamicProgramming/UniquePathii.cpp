/*
 * LeetCode 63 Unique Paths ii
 * Medium
 * Jiawei Wang
 * 2021 8.13
 */

/* 
 * Revision
 * $1 2021.11.2 Jiawei Wang
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // DP
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));

	for (int i = 0; i < obstacleGrid.size(); i++) {
	    vector<int> vi = obstacleGrid[i];
	    for (int j = 0; j < vi.size(); j++) {
		if (vi[j] == 1) dp[i][j] = -1;
	    }
	}

	if (dp[m-1][n-1] == -1 || dp[0][0] == -1) return 0; 
	for (int i = 0; i < m; i++) if (dp[i][0] != -1) dp[i][0] = 1; else break;
	for (int j = 0; j < n; j++) if (dp[0][j] != -1) dp[0][j] = 1; else break;
	
	for (int i = 1; i < m; i++) {
	    for (int j = 1; j < n; j++) {
		if (dp[i][j] == -1) continue;
		if (dp[i-1][j] == -1 && dp[i][j-1] == -1) dp[i][j] = 0;
		else if (dp[i-1][j] == -1) dp[i][j] = dp[i][j-1];
		else if (dp[i][j-1] == -1) dp[i][j] = dp[i-1][j];
		else dp[i][j] = dp[i-1][j] + dp[i][j-1];
	    }
	}
        
	return dp[m-1][n-1];
    }
};
