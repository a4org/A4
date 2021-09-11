/*
 * LeetCode 740 Delete And Earn
 * Medium
 * Jiawei Wang
 * 2021 9.11
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
	if (nums.empty()) return 0;
	const auto range = minmax_element(nums.begin(), nums.end()); // find the boundary
	const int l = *(range.first);
	const int r = *(range.second);
	vector<int> points(r - l + 1, 0); // there are r - l elements inside [r, l]
	for (const int num : nums) {
	    points[num-l] += num;
	}
	return rob(points);
    }

private:
    int rob(const vector<int>& nums) {
	int rob = 0;
	int norob = 0;

	for (int i = 0; i < nums.size(); i++) {
	    int rob_tmp = rob;
	    int norob_tmp = norob;

	    // if we choose to rob this: (must came from norob)
	    rob = norob_tmp + nums[i];
	    // if we choose do not rob:
	    norob = max(rob_tmp, norob_tmp);
	}
	return max(rob, norob);
    }
};


