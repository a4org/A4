/*
 * LeetCode 368 Largest Divisible Subset
 * Medium
 * Jiawei Wang
 * 2021 11.15
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	if (n == 0) return {};

	vector<int> dp(n, 1); // dp[i]: considering nums[0:i], the LDS ending with nums[i]
	vector<int> prev(n, -1); // Backtracking

	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < i; j++) {
		if (nums[i] % nums[j] == 0) {
		    dp[i] = max(dp[i], dp[j]+1);
		    if (dp[i] == dp[j]+1) {
			// update
			prev[i] = j;
		    }
		}
	    }
	}

	int mlen = 0;
	int idx;
	for (int i = 0; i < n; i++) {
	    if (dp[i] > mlen) {
		mlen = dp[i];
		idx = i;
	    }
	}

	vector<int> ret;
	while (idx != -1) {
	    ret.push_back(nums[idx]);
	    idx = prev[idx];
	}
	return ret;
    }
}

