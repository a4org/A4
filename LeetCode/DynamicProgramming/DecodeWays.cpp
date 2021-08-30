/*
 * LeetCode 91  Decode Ways
 * Medium
 * Jiawei Wang
 * 2021 6.8
 */


/*
 
   dp[i] = dp[i-1] (if the last digit is valid) + dp[i-2] (if the last two digit is valid)
   valid means can obtain a 1 - 26 number
 
 */

/* Revision:
 * $1 2021.8.30 Jiawei Wang:
 * dp[i] stands for all possible number of ways till ith day
 */

#include <iostream>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int numDecodings(string s) {
	if (s.size() == 0) return 0;

	int N = s.size();
	s = "#" + s;
	vector<int> dp(N+1, 0);

	dp[0] = 1;
	dp[1] = s[1]=='0' ? 0 : 1; // first digit

	for (int i = 2; i <= N; i++) {
	    // check if s[i] alone can stand for a letter
	    if (s[i] != '0') dp[i] += dp[i-1];

	    // check if s[i-1:i] can stand for a letter
	    if (s[i] >= '0' && s[i] <= '6' && (s[i-1] == '1' || s[i-1] == '2')) {
		// (10, 16) (20, 26)
		dp[i] += dp[i-2];
	    } else if (s[i] >= '7' && s[i] <= '9' && s[i-1] == '1') {
		// (17, 19)
		dp[i] += dp[i-2];
	    }
	}
	return dp[N];
    }
};
