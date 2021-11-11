/*
 * LeetCode 1413 Minimum Value to Get Positive Step by Step Sum
 * Easy
 * Shuo Feng
 * 2021.11.11
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Brute Force.
 */

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1;
        while (1) {
            int sum = res;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];

                if (sum < 1)
                    break;
                if (sum >= 1 && i == nums.size() - 1)
                    return res;
            }
            res += 1;
        }
    }
};
