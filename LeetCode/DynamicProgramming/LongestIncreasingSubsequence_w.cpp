/*
 * LeetCode 300 Longest Increasing Subsequence
 * Medium
 * Jiawei Wang
 * 2021 9.8
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	int ret = 1;
	vector<int> dp(n, 1);
	// dp[i] := the num of numbers in nums[i, n] that are strictly increasing
	for (int i = n-1; i >= 0; i--) {
	    for (int j = i; j < n; j++) {
		if (nums[j] > nums[i]) {
		    dp[i] = max(dp[j]+1, dp[i]);
		    ret = max(dp[i], ret);
		}
	    }
	}
	return ret;
    }
};
