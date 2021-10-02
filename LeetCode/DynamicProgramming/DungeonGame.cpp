/*
 * LeetCode 174 Dungeon Game
 * Hard
 * Jiawei Wang
 * 2021 10.2
 */

// Dynamic Programming
// all cases and subproblems
//
// Difference Between DP and Greedy:
// A Problem: ->
// DP: Sub"Problems" (Each Problems is just like the hole problem format)
// Greedy: Sub"Steps"

#include <vector>

using namespace::std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
	// dp[i][j] represents the minimum health required that you can reach the bottom-right corner
	
	int m = dungeon.size();
	int n = dungeon[0].size();

	vector<vector<int>> dp(m, vector<int>(n));


	for (int i = m-1; i >= 0; i--) {
	    for (int j = n-1; j >= 0; j--) {
		if (i == m-1 && j == n-1) dp[i][j] = 1; // cannot drops to 0 or below
		else if (i == m-1) {
		    // bottom line (only reachable from right)
		    dp[i][j] = dp[i][j+1] - dungeon[i][j+1];
		}
		else if (j == n-1) {
		    // left line (only reachable from bottom)
		    dp[i][j] = dp[i+1][j] - dungeon[i+1][j];

		} else {
		    // two directions
		    dp[i][j] = min(dp[i][j+1] - dungeon[i][j+1], dp[i+1][j] - dungeon[i+1][j]);
		}

		dp[i][j] = max(1, dp[i][j]);  // if two many power-ups, we don't want too much blood
	    }
	}

	// at the begining also need a quest
	dp[0][0] = dp[0][0] - dungeon[0][0];
	dp[0][0] = max(dp[0][0], 1);

	return dp[0][0];
    }
};

