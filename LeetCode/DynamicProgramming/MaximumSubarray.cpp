/*
 * LeetCode 53 Maximum Subarray
 * Easy
 * Jiawei Wang
 * 2021 8.15
 */

/* Revision
 * $1 2021.10.5 Jiawei Wang
 *
 * $2 2022.5.6  Jiawei Wang
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 Recursion with DP
    // Time Complexity: O(n^2) (TLE)
    int maxSubArray1(vector<int>& nums) {
	const int size = nums.size();
	int maximum = INT_MIN;
	vector<vector<int>> dp(size, vector<int>(size)); // dp[i][j] represents the sum from i to j
	for (int i = 0; i < size; i++) {
	    for (int j = i; j < size; j++) {
		int& sum = dp[i][j];
		sum = (j-1>=0 ? dp[i][j-1] : 0) + nums[j];
		maximum = max(maximum, sum);
	    }
	}
	return maximum;
    }

    // #2 Kadane's algorithm
    // Subarray
    int maxSubArray2(vector<int>& nums) {
	int ans = INT_MIN, a = 0;
	for (int x : nums) {
	    a += x;
	    ans = max(ans, a); // record the ans first
	    a = max(a, 0);     // if a < 0 (the sum till now) just set it to 0 and continue
	}
	return ans;
    }
};
