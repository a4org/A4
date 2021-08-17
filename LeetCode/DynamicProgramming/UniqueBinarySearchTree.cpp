/*
 * LeetCode 96 Unique Binary Search Tree
 * Medium
 * Shuo Feng
 * 2021.8.17
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(1 + n);
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                nums[i] += nums[j] * nums[i - j - 1];
            }
        }
        return nums[n];
    }
};
