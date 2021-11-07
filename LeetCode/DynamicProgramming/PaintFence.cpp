/*
 * LeetCode 276 Paint Fence
 * Medium
 * Jiawei Wang
 * 2021 11.7
 */

class Solution {
public:
    int numWays(int n, int k) {
	// Dynamic Programming
	// X Y Z
	// same[k] : # of methods that satisfy nums[k-1] == nums[k]
	// diff[k] : # of methods that satisfy nums[k-1] != nums[k]
	//
	// State-transfer equation:
	// same[k] = diff[k-1] (if we wants nums[k] == nums[k-1] then nums[k] only have one choice)
	// diff[k] = same[k-1] * (k-1) + diff[k-1] * (k-1)
	// (if we wants nums[k] != nums[k-1] then nums[k] have (k-1) choice)
	
	if (n == 0) return 0;
	if (n == 1) return k;

	int same = k;
	int diff = k * (k-1);

	int same_old, diff_old;

	for (int i = 3; i < n; i++) {
	    // start from the third element
	    same_old = same; diff_old = diff;
	    same = diff_old;
	    diff = (diff_old + same_old) * (k-1);
	}
	return same + diff;
    }
};

