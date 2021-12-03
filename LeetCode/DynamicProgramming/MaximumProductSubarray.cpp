/*
 * LeetCode 152 Maximum Product Subarray
 * Medium
 * Jiawei Wang
 * 2021 12.03
 */

#include <vector>

using namespace::std;

// Dynamic Programming
// it is some kind of "greedy"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)  return 0;

	int ret = nums[0];
	int currMax = nums[0];
	int currMin = nums[0];

	for (int i = 1; i < n; i++) {
	    int nextMax = currMax * nums[i];
	    int nextMin = currMin * nums[i];

	    currMax = max(nums[i], max(nextMax, nextMin));
	    currMin = min(nums[i], min(nextMax, nextMin));

	    ret = max(ret, currMax);
	}

	return ret;
    }


    // #2 Lee's elegant solution
    int maxProduct2(vector<int> A) {
	int n = A.size(), res = A[0], l = 0, r = 0;
	for (int i = 0; i < n; i++) {
	    l =  (l ? l : 1) * A[i];
	    r =  (r ? r : 1) * A[n - 1 - i];
	    res = max(res, max(l, r));
	}
	return res;
    }
};


