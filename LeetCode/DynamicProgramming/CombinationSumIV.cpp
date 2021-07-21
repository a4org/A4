/*
 * LeetCode 377  Combination Sum IV
 * Medium
 * Jiawei Wang
 * 2021 6.18
 *
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
	for (int x : nums) {
	    if (sum - x >= 0) dp[sum] += dp[sum-x];
	}
    }
    return dp[target];
}
