/*
 * LeetCode 486 Predict The Winner
 * Medium
 * Jiawei Wang
 * 2021 9.6
 */

/*
 * Region dp
 */

#include <vector>
#include <numeric>

using namespace::std;

// Player 1 can win return false
// Translete -> find all possible Player1 score, and check whether he can get half of the total sum score
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
	int n = nums.size();

	if (n == 1) return true;
	// dp[i][j] -> the maximum score Player1 can get in nums[i, j]
	vector<vector<int>> dp(n, vector<int>(n));
	int sum = accumulate(nums.cbegin(), nums.cend(), 0); // just check whether get the half

	// key: Think about what are absolutely correct
	for (int i = 0; i < n; i++)
	    // length == 1
	    dp[i][i] = nums[i];

	for (int i = 0; i < n-1; i++) 
	    // length == 2
	    dp[i][i+1] = max(nums[i], nums[i+1]);

	for (int l = 3; l <= n; l++) {
	    // length (start from 3)
	    for (int i = 0; i + l - 1 < n; i++) {
		int j = i + l - 1; // []
		// for every nums[i][j]
		int left = min(dp[i+2][j], dp[i+1][j-1]) + nums[i];  // pick left
		int right = min(dp[i][j-2], dp[i+1][j-1]) + nums[j]; // pick right
		dp[i][j] = max(left, right);
	    }

	}

	return dp[0][n-1] * 2 >= sum;
    }
};
