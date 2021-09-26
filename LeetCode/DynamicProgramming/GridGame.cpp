/*
 * LeetCode 5882 Grid Game
 * Medium
 * Jiawei Wang
 * 2021 9.26 (Contest 260)
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // DP
    // key: When A choose to go down (n cases)
    long long gridGame(vector<vector<int>>& grid) {
	int n = grid[0].size();
	long long left = 0, right = 0;
	for (int i = 1; i < n; ++i) {
	    right += grid[0][i];
	}

	long long ans = right;
	for (int i = 1; i < n; ++i) {
	    left += grid[1][i-1], right -= grid[0][i];
	    ans = min(ans, max(left, right)); // just need to find the minimum score of B
	}
	return ans;
    }
};


