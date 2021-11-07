/*
 * LeetCode 485 Max Consecutive Ones
 * Easy
 * Jiawei Wang
 * 2021.11.7
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
	int ret = 0;
	int curr = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
	    if (nums[i] == 1) {
		curr += 1;
	    } else {
		ret = max(ret, curr);
		curr = 0;
	    }
	}
	return ret;
    }
};


