/*
 * LeetCode 312 Burst Balloons
 * Hard
 * Jiawei Wang
 * 2021 8.13
 */

/*
 * Dynamic Programming
 * Notice:
 * #1: We shouldn't just go from left to right,
 * becasue we might pop balloons in some very strange order
 *
 * #2: From time to time, we should consider analyzing the process backwards
 * instead of thinking which balloon I should pop first, 
 * I will think which balloon I should pop last
 *
 * Key: After deciding which to pop last
 * which means the i cannot be destroyed before the interval (i+1, R) and (L, i-1)
 * Then we can get current Maximum score of this Interval and store it
 * Keep doing it while decreasing L and increasing R
 * then return dp[0][n-1] (n is the size)
 *
 * #3: For each positions i inside (L, R)
 * we check whether pop it last will get the maximum scores
 * And that is the maximum score of current interval
 *      
 *
 */
#include <vector>

using namespace::std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
	int n = nums.size();
	if (nums.empty()) {
	    return 0;

	}
	// dp[R][L] represents the maximum score inside the interval (R, L)
	vector<vector<int>> dp(n, vector<int>(n)); // dp table

	for (int L = n - 1; L >=0; L--) {
	    // decreasing L
	    for (int R = L; R < n; R++) {
		// increasing R 
		// inside this [L, R] intrval
		for (int i = L; i <= R; i++) {
		    // for each i in the current interval 
		    // treat it as the last pop number and get the current maximum score (compare)
		    dp[L][R] = max(dp[L][R],
			    nums[i]*(L?nums[L-1]:1)*(R==n-1?1:nums[R+1])  // the last pop score
			    + (L<=i-1?dp[L][i-1]:0) + (R>=i+1?dp[i+1][R]:0)); // plus two intervals near i (maximum)
		}
	    }
	}
	return dp[0][n-1];
    }
};

