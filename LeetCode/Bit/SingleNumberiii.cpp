/*
 * LeetCode 260 Single Number iii
 * Medium
 * Jiawei Wang
 * 2021.11.6
 */

#include <vector>

using namespace::std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // first just xor all
	long long diff = 0;
	for (int n : nums) {
	    diff ^= n;
	}

	// Suppose the return two number is x and y
	// diff is the XOR of x, y (x^y)
	// then we wants to find x and y separately
	
	// just to find the rightmost 1-bit
	int rightmost = diff & (-diff);

	int ret = 0;
	for (int n : nums) {
	    if ((n & rightmost) != 0) ret ^= n;
	}
	int ret2 = ret ^ diff;

	return {ret, ret2};
    }
};
