/*
 * LeetCode 55 Jump Game
 * Medium
 * Jiawei Wang
 * 2021 8.11
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
};
