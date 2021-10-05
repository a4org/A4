/*
 * LeetCode 70 Climbing Stairs
 * Easy
 * Shuo Feng
 * 2021.10.5
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Dp
 *   Each time we can climb one step or two step, so there is two cases when climb to nth stair: from 'n - 1' stair or from 'n - 2' stair.
 *   consider of these cases, if we use 'dp[n]' to stand all distinct ways to nth stairs, conclusion is: dp[n] = dp[n - 1] + dp[n - 2].
 */

class Solution {

public:
    int climbStairs(int n) {
        
        // All distinct ways to nth stairs.
        vector<int> dp(n + 1, 0);
        if (n == 1)return 1;
      
        // Beginning situations.
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
