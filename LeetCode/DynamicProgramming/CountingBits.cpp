/*
 * LeetCode 338 Counting Bits
 * Easy
 * Jiawei Wang
 * 2021 8.24
 */

#include <vector>

using namespace::std;

class Solution {
public:
    //.#1 DP
    vector<int> countBits1(int num) {
	vector<int> dp(num+1);
	int offset = 1;

	// Must have some relationship with "2"
	// add one on the front (understand

	for (int i = 1; i <= num; ++i) {
	    if (offset * 2 == i) {
		// Current cycle
		offset *= 2;
	    }
	    dp[i] = dp[i-offset] + 1;
	}

	return dp;
    }






    // #2 Special Binary Operation '&'
    // Time Complexity: O(n)
    vector<int> countBits2(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};
