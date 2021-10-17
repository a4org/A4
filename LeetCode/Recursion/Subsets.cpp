/*
 * LeetCode 78 Subsets
 * Medium
 * Jiawei Wang
 * 2021 10.17
 */

#include <vector>

using namespace::std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();

	vector<vector<int>> ret = {};
	helper(nums, ret, 0, {}, n);

	return ret;
    }

private:
    void helper(vector<int> nums, vector<vector<int>>& ret, int index, vector<int> current, int n) {
	if (index == n) {
	    // Termination Condition
	    ret.push_back(current);
	    return;
	}
	helper(nums, ret, index+1, current, n);
	current.push_back(nums[index]);
	helper(nums, ret, index+1, current, n);
	return;
    }
};

