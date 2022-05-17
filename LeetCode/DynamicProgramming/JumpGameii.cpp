/*
 * LeetCode 45 Jump Game ii
 * Medium
 * Jiawei Wang
 * 2021 8.11
 */

/* Revision
 * $1 2022.5.17 Jiawei Wang
 */

/*
 * #1 Greedy
 *
 * #2 DP
 */
#include <vector>

using namespace::std;

class Solution {

public:
    // #1 Greedy
    int jump1(vector<int>& nums) {
	int steps = 0;
	int near = 0;
	int far = 0;
	for (int i = 0; i < nums.size(); ++i) {
	  if (i > near) {
	    ++steps;
	    near = far;
	  }
	  far = max(far, i + nums[i]);      
	}
	return steps;
    }

    // #2 DP I
    int jump2(vector<int>& nums) {
	int size = nums.size();
	vector<int> jumptimes(size, INT_MAX / 2);
	jumptimes[0] = 0;

	for (int i = 0; i < size; i++) {
	    int mdistance = nums[i];  // maximum distance
	    for (int j = i+1; j <= i+mdistance && j < size; j++) 
		jumptimes[j] = min(jumptimes[i]+1, jumptimes[j]);
	}
	return jumptimes[size-1];
    }
};
