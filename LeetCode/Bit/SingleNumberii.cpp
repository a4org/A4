/*
 * LeetCode 137 Single Number ii
 * Medium
 * Jiawei Wang
 * 2021.11.6
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
	vector<int> Bits(32, 0);
	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
	    int n = nums[i];
	    for (int j = 0; j < 32; j++) {
		Bits[j] += ((n >> j) & 1); // get the jth bit
		// Ex. n = 01100, j = 2
		// 00011 & 00001 -> 1
	    }
	}

	for (int j = 0; j < 32; j++) {
	    if (Bits[j] % 3 != 0) {
		ret += 1 << j;
	    }

	}
	return ret;
    }
};

