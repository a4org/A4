/*
 * LeetCode 136 Single Number
 * Easy
 * Jiawei Wang
 * 2021.11.6
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 Sorting O(NlogN) 
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n-1; i++) {
            if (nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        }
        return (nums[0] == nums[1]) ? nums[n-1] : nums[0];
    }

    // #2 Bit XOR 
    int singleNumber2(vector<int>& nums) {
	int ret = 0;
	for (auto n : nums) {
	    ret ^= n;
	}
	return ret;
    }

    // 2 ^ 1 ^ 3 ^ 2 ^ 3
    // Communication Law
    // 2 ^ 2 ^ 3 ^ 3 ^ 1
    // the same number will become 0
    // 2 ^ 2 = 0, 3 ^ 3 = 0
};
