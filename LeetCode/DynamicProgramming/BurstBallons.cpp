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

/* Revision
 * $1 2021.11.6 
 * Region DP
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

    // Region DP:
    // dp[i][j]: Maximum coins you can collect by bursting the ballons[i:j]
    //
    // {i X X X X X X X X} [k] {X X X X X X X X X j}
    //
    // dp[i][k-1] + dp[k+1][j] + nums[k] * nums[i-1] * nums[j+1]
    // from small region to large region
    int maxCoins2(vector<int>& nums) {
	int n = nums.size();
	if (nums.empty()) {
	    return 0;
	}
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); // to store the boundary cases (Overflow)

	for (int len = 1; len <= n; len++) {
	    // for diff length of the interval size
	    for (int i = 1; i+len-1 <= n; i++) {
		// start point of the interval
		int j = i + len - 1; // interval [i:j]
		for (int k = i; k <= j; k++) {
		    // k can be any point of this interval [i:j]
		    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[k] * nums[i-1] * nums[j+1]);
		}
	    }
	}
	return dp[1][n];
    }
};

