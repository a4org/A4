/*
 * LeetCode 70 Climbing Stairs
 * Easy
 * Jiawei Wang
 * 2021 10.5
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int climbStairs(int n) {
	vector<int> dp(n+1); // dp[i] represents the ways to reach i

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 2; i <= n; i++) {
	    dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
    }
};
