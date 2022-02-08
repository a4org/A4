/* 
 * LeetCode 1774 Closest Dessert Cost
 * Medium
 * Jiawei Wang
 * 2022.2.8
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 DFS
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
	int ret1 = INT_MAX/2;  // return that larget than target
	int ret2 = INT_MIN/2;  // return that less than target

	for (int base : baseCosts) {
	    helper(ret1, ret2, toppingCosts, target, base, 0);
	}

	int abs1 = ret1 - target;
	int abs2 = target - ret2;

	if (abs2 <= abs1) return ret2;
	else return ret1;
    }

private:
    void helper(int& ret1, int& ret2, vector<int>topping, int target, int curr, int idx) {

	int tmpdiff = target - curr;

	if (tmpdiff < 0 && tmpdiff > target - ret1) ret1 = curr;
	else if (tmpdiff >= 0 && tmpdiff < target - ret2) ret2 = curr;

	if (ret1 < curr || idx >= topping.size()) {
	    // Termination Condition
	    return;
	}

	// 3 Options
	helper(ret1, ret2, topping, target, curr, idx+1);
	helper(ret1, ret2, topping, target, curr + topping[idx], idx+1);
	helper(ret1, ret2, topping, target, curr + topping[idx]*2, idx+1);
    }
};
