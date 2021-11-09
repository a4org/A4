/*
 * LeetCode 90 Subsets ii
 * Medium
 * Jiawei Wang
 * 2021 10.17
 */

/*
 * Revision
 * $1 2021.11.9 Jiawei Wang
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();
	// sorting guarantee that duplicate subsets can only appear with the same order
	sort(nums.begin(), nums.end()); 

	vector<vector<int>> ret = {};
	helper(nums, ret, 0, {}, n);

	return ret;
    }

private:
    void helper(vector<int> nums, vector<vector<int>>& ret, int index, vector<int> current, int n) {
	if (index == n) {
	    // Termination Condition
	    if (find(ret.begin(), ret.end(), current) == ret.end()) 
		// no duplicate
		ret.push_back(current); 
	    return;
	}
	helper(nums, ret, index+1, current, n);
	current.push_back(nums[index]);
	helper(nums, ret, index+1, current, n);
	return;
    }
};


