/*
 * LeetCode 213 House Robber ii
 * Medium
 * Jiawei Wang
 * 2021 7.25
 */

/* #1 DP
 * Like 198-House Robber, but with two cases:
 * 1: rob first house => Y N [3 to i-1] N
 * 2: not rob first house => N [2 to i]
 */

/* Revision
 * $1 2021.9.9 Jiawei Wang
 * Consider all cases (classify)
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        
        int ret = 0;
        
	// Case 2 do not rob first house
        int rob = nums[1], norob = 0;        
        for (int i=2; i<n; i++) {
            int rob_tmp = rob, norob_tmp = norob;
            rob = norob_tmp + nums[i];
            norob = max(rob_tmp, norob_tmp);            
        }
        ret = max(rob, norob);
        
	// Case 1 rob the first house
        rob = nums[0], norob =0;
        for (int i=1; i<n-1; i++) {
            int rob_tmp = rob, norob_tmp = norob;
            rob = norob_tmp + nums[i];
            norob = max(rob_tmp, norob_tmp);   
        }
        ret = max(ret, max(rob, norob));
        return ret;
    }
};
