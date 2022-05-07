/*
 * LeetCode 300 Longest Increasing Subsequence
 * Medium
 * Jiawei Wang
 * 2021 9.8
 */

/* Revision
 * $1 2022.1.3 Jiawei Wang
 * $2 2022.5.7 Jiawei Wang
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 DP
    // DP Basic II
    // O(n^2)
    int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 1); 
	// all cases
	// dp[i]: the length of longest increasing subsequence for nums[0:i]
	// ending with nums[i]

	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < i; j++) {
		if (nums[j] < nums[i]) {
		    dp[i] = max(dp[i], dp[j]+1);
		}
	    }
	}
	int ret = 0;
	for (auto n : dp) ret = max(ret, n);
	return ret;
    }

    // #2 Greedy
    // O(nlogn)
    // https://www.youtube.com/watch?v=Q6KyDl_xiIg
    int lengthOfLIS2(vector<int>& nums) {
	int n = nums.size();
	vector<int> q; // longest Increasing Subsequence (LIS)

	for (int x : nums) {
	    auto pos = lower_bound(q.begin(), q.end(), x);
	    // find the first position that greater than x in q (using binary search)
	    if (pos == q.end()) {
		q.push_back(x);  // just push_back
	    } else {
		*pos = x; // make a "better" LIS (smaller)
	    }
	}
	return q.size();
    }
};
