/*
 * LeetCode 2044 Count Number of Maximum Bitwise-OR Subsets
 * Medium
 * Jiawei Wang
 * 2021.10.17
 */

 // LeetCode Weekly Contest #263

#include <vector>

using namespace::std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
	int a = 0;
	
	for(auto i : nums) {
	    a = a | i;
	}
	// a is the maximum Bitwise-OR value
	
	int ans = subset(nums, nums.size()-1, a, 0);
	    
	return ans ;
	
    }

private:
    int subset(vector<int> &nums, int i, int a, int b) {
	int ans = 0; // this layer
	if (i < 0)
	    // Termination Condition
	    return 0;

	if (a == (b | nums[i]))
	    // got one more answer
	    ans = 1;

	// both pick this element and not
	return ans + subset(nums, i - 1, a, b) + subset(nums, i - 1, a, b | nums[i]);
    }
};
