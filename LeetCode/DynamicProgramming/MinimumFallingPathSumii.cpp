/*
 * LeetCode 1289 Minimum Falling Path Sum ii
 * Hard
 * Jiawei Wang
 * 2021 11.7
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
	// Pretty like LC 265 Paint House ii
	
	int n = grid.size();
	if (n == 0) return 0;

	int m = grid[0].size();

	vector<int> dp(grid[0].begin(), grid[0].end());

	for (int i = 1; i < n; i++) {
	    vector<pair<int, int>> temp; // sort temp each layer

	    for (int j = 0; j < m; j++) {
		temp.push_back({dp[j], j});
	    }
	    sort(temp.begin(), temp.end());

	    for (int j = 0; j < m; j++) {
		if (j != temp[0].second) {
		    // we can pick the smallest element of i-1 th layer if we wants to pick grid[i][j]
		    dp[j] = temp[0].first + grid[i][j];
		} else {
		    dp[j] = temp[1].first + grid[i][j];
		}
	    }

	}
	int ret = INT_MAX / 2;
	for (int i = 0; i < m; i++) {
	    if (ret > dp[i]) {
		ret = dp[i];
	    }
	}
	return ret;
    }
};

