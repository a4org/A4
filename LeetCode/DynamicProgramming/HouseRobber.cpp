/*
 * LeetCode 198 House Robber
 * Medium
 * Jiawei Wang
 * 2021 7.25
 */

/* Revision
 * $1 2021.9.9 Jiawei Wang
 * a simple dp question
 */

/* DP (dual status)
 * choose i => not choose i-1
 * not choose i => choose i-1 or not choose i-1
 *
 * dp[choose i]: maximum amount of money you can rob when you rob i
 * dp[not choose i]: maximum amount of money you can rob when you not rob i
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int rob(vector<int>& nums) {
	int robdp = nums[0]; // maximum amount of money you can rob when you rob ith house
	int norobdp = 0;     // maximum amount of money you can rob when you do not rob ith house

	for (int i = 1; i < nums.size(); i++) {
	    int rob_tmp = robdp;
	    int norob_tmp = norobdp;

	    robdp = norobdp + nums[i];         // when you want to rob current house
	    norobdp = max(rob_tmp, norob_tmp); // two choices
	}

	return max(robdp, norobdp);
    }
};


