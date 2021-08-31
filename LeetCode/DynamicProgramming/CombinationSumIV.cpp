/*
 * LeetCode 377  Combination Sum IV
 * Medium
 * Jiawei Wang
 * 2021 6.18
 *
 */

/* Revision:
 * $1 2021.8.31 Jiawei Wang
 * Example:
 * nums [1, 2, 3] target 4
 *
 * dp[5] (0, 1, 2, 3, 4)
 * sum = 1; [1, 1, 0, 0, 0]
 * sum = 2: [1, 1, 2, 0, 0]
 * sum = 3: [1, 1, 2, 4, 0]
 * sum = 4: [1, 1, 2, 4, 7]
 *
 * Think about why it correct
 */

#include <iostream>
#include <vector>

using namespace::std;

int CombinationSumIV(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1, 0);
    // dp[i] stores the number of combinations that can get i
    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++) {
	// for every sum from 1 to sum, traverse the hole nums to find the number of combinations
	// each node can choosse any nums each time
	for (int x : nums) {
	    if (sum - x >= 0) dp[sum] += dp[sum-x];
	}
    }
    return dp[target];
}
