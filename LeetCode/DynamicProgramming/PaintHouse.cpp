/*
 * LeetCode 256 Paint House
 * Medium
 * Jiawei Wang
 * 2021 11.7
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
	// the status of day i just depends on the i-1 day
	// dp[i][0] -> choose red
	// dp[i][1] -> choose blue
	// dp[i][2] -> choose green
	int n = costs.size();
	if (n == 0) return 0;
	int red = costs[0][0];
	int blue = costs[0][1];
	int green = costs[0][2];

	int old_red, old_blue, old_green;

	for (int i = 1; i < n; i++) { 
	    old_red = red;
	    old_blue = blue;
	    old_green = green;

	    red = min(old_blue, old_green) + costs[i][0]; // choose red
	    blue = min(old_red, old_green) + costs[i][1]; // choose blue
	    green = min(old_blue, old_red) + costs[i][2]; // choose green
	}
	return min(red, max(blue, green));
    }
};
