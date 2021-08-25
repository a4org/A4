/*
 * LeetCode 300 Longest Increasing Subsequence
 * Medium
 * Shuo Feng
 * 2021.8.25
 */

/*
 * Solution 1 Dp
 * 
 *   Use " max_size " to stand the longest increasing subsequense to place " i ", each time check the number before " i "(check place " j "),
 *  if " nums[i] " is the bigger one, increasing subsequence is founding, choose the bigger one between " max_size[i] " and " max_size[j] + 1 "
 *  as the longest length to place " i ".
 *
 *   The reason why search the place befor " i ":
 *  In Dp we should judge the situation acording to the conditions we have known, " max_size[] " after place " i " still need judgement.
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 1;
        if (size < 1) return 0;

        vector<int> max_size(size, 0);
        for (int i = 0; i < size; ++i) {
            max_size[i] = 1;  // Initial case of each points

            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    max_size[i] = max(max_size[j] + 1, max_size[i]);
                }
            }
        }
        // Get the maximum one
        int p = INT_MIN;
        for (int i = 0; i < size; ++i)
            p = max(p, max_size[i]);
        return p;
    }
};


/*
 * Solution 2
 */
