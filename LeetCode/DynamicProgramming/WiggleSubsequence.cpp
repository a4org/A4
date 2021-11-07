/*
 * LeetCode 376 Wiggle Subsequence
 * Medium
 * Jiawei Wang
 * 2021 8.17
 */

/* Revision
 * $1 2021.11.7 Jiawei Wang
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 O(n^2) dp (brute force)
    int wiggleMaxLength(vector<int>& nums) {
	// two status
	const int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(2));
	// 2021.8.24: sequence! (status -- DP) (House Robber) (188 Best time to buy and sell stock iv)
	// dp[i][0] --> smaller length
	// dp[i][1] --> larger length
	int answer = 0;

	for (int i = 0; i < n; ++i) {
	    dp[i][0] = dp[i][1] = 1; // at current index minimum WM length is 0
	    for (int j = 0; j < i; ++j) {
		// for each element before i
		if (nums[j] < nums[i]) {
		    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}

		if (nums[j] > nums[i]) {
		    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
		}
	    }
	    answer = max({answer, dp[i][0], dp[i][1]});
	}
	return answer;
    }

    int wiggleMaxLength2(vector<int>& nums) {
        // DP
        // for each number in the sequence
        // two possible status -> up / down
        // up[i] -> the longest wiggle subsequence of interval [0:i] with last positive difference
        // down[i] -> the longest wiggle subsequence of intervel [0:i] with last negative difference
        
        int n = nums.size();
        vector<int> up(n+1);
        vector<int> down(n+1);
        if (n == 0) return 0;    
        
        up[0] = 1;
        down[0] = 1;
        
        for (int i = 1; i < n; i++) {
            // for each number in nums
            if (nums[i] > nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            } else if (nums[i] < nums[i-1]) {
                down[i] = down[i-1];
                up[i] = down[i-1] + 1;
            } else {
                // equal
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up[n-1], down[n-1]);
    }
};

