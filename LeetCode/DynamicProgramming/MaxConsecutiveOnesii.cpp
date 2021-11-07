/*
 * LeetCode 487 Max Consecutive Ones ii
 * Medium
 * Jiawei Wang
 * 2021.11.7
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;

	int dp0 = 0, dp1 = 0;
	int old_dp0, old_dp1;
	int ret = 0;

	for (int i = 0; i < n; i++) {
	    old_dp0 = dp0;
	    old_dp1 = dp1;

	    if (nums[i] == 0) {
		dp1 = old_dp0 + 1;
		dp0 = 0;
	    } else {
		dp1 = old_dp1 + 1;
		dp0 = old_dp0 + 1;
	    }

	    ret = max(ret, max(dp0, dp1));
	}
	return ret;
    }
};

