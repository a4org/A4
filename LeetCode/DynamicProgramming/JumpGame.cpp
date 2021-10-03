/*
 * LeetCode 55 Jump Game
 * Medium
 * Jiawei Wang
 * 2021 8.11
 */

/* Revision
 * $1 2021.10.3 Jiawei Wang
 */

#include <vector>

using namespace::std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
	int maxjump = 0; 
	int size = nums.size();

	for (int i = 0; i < size; i++) {
	    if (maxjump < i) return false;
	    maxjump = max(i + nums[i], maxjump);
	    if (maxjump >= size-1) return true;
	}
	return false;
    }

    // dp[i] => the maximum jump distance in index i
    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n);
     
    
        if (n == 1 || n == 0) return true;
        if (nums[0] == 0) return false;
        dp[0] = nums[0];

        for (int i = 1; i < n-1; i++) {
            dp[i] = max(dp[i-1]-1, nums[i]);
            if (dp[i] == 0) return false; 
        }
        
        return (dp[n-2] > 0);
    }
};
