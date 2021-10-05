/*
 * LeetCode 343 Integer Break
 * Medium
 * Jiawei Wang
 * 2021 10.5
 */



#include <vector>

using namespace::std;

class Solution {
public:
    // Classic DP
    // a = b + c
    // a = (a1 + a2 + a3) + (... + ak-1 + ak)
    //           b                  c
    int integerBreak(int n) {
	vector<int> dp(n + 1, 0); // dp[i] represents the maximum product of i

	if (n == 2) return 1;
	if (n == 3) return 2;

	dp[2] = 2; // when other larger number need to use dp[2], we just keep it, do not broke it
	dp[3] = 3; // same as dp[3]

	for (int i = 4; i <= n; i++) {
	    int tmp = 0;
	    for (int j = 2; j <= i/2; j++) {
		if (dp[j] * dp[i-j] > tmp)
		    tmp = dp[j] * dp[i-j];
		// using max is much slower
	        // dp[i] =max(dp[i], dp[j] * dp[i-j]);
	    }
	    dp[i] = tmp;
	}
	return dp[n];
    }
};
