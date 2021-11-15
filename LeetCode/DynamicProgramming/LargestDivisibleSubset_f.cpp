/*
 * LeetCode 368 Largest Divisible Subset
 * Medium
 * Shuo Feng
 * 2021.11.15
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * Solution: Dp
 */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(size, 0);  // The size of lds in nums[0 : i], which is ended with nums[i].
        vector<int> pre(size, 0); // pre[i] shows previous element of i.

        for (int i = 0; i < size; ++i) {
            int len = 1;  // Begin with len 1;
            int prev = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                  
                    // If reach larger length -> update.
                    if (len < dp[j] + 1) {
                        len = dp[j] + 1;
                        prev = j;
                    }
                }
            }
            dp[i] = len;
            pre[i] = prev;
        }

        // Find the largest length and the place of last element.
        int max = INT_MIN;
        int idx;
        for (int i = 0; i < size; i++) {
            if (dp[i] > max) {
                max = dp[i];
                idx = i;
            }
        }

        vector<int> res;
        // Add elements to res until it reach largest length.
        while (res.size() != max) {
            res.push_back(nums[idx]);
            // Tracking Back.
            idx = pre[idx];
        }
        return res;
    }
};
