/*
 * LeetCode 416 Partition Equal Subset Sum
 * Medium
 * Jiawei Wang
 * 2021 12.12
 */


#include <vector>
#include <numeric>

using namespace::std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
	// #2 DP
	// Instead of trying permutations, we just care about whether we can get target sum
	// dp[s] : whether we can find a subset whose sum equal to s
	// 0 ~ 2e4

	int sum = accumulate(nums.begin(), nums.end(), 0);

	if (sum % 2 != 0) return false; // must be an odd number

	vector<int> dp(sum/2+1, 0);
	dp[0] = true;

	for (int x : nums) {
	    auto dp2 = dp;
	    for (int s = 0; s <= sum/2; s++) {
		if (s - x >= 0 && dp2[s-x] == true) {
		    dp[s] = true;
		}
	    }
	}
	return dp[sum/2];
    }
};
