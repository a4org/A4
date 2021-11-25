/*
 * LeetCode 53 Maximum Subarray
 * Easy
 * Shuo Feng
 * 2021.11.25
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Dp
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = nums[0];
        for (int x : nums) {
            pre = max(pre + x, x);
            ans = max(ans, pre);
        }
        return ans;
    }
};
