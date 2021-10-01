/*
 * LeetCode 78 Subsets
 * Medium
 * Shuo Feng
 * 2021.10.1
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution :Backtracking
 */

class Solution {
private:
    vector<vector<int>> res;
    void findsubsets(vector<int>& nums, vector<int>& combo, int level) {
        if (level == nums.size()) {
            res.push_back(combo);
            return;
        }
        combo.push_back(nums[level]);
        findsubsets(nums, combo, level + 1);
        combo.pop_back();
        findsubsets(nums, combo, level + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> combo;
        int level = 0;
        findsubsets(nums, combo, level);
        return res;
    }
};
