/*
 * LeetCode 123  Best Time to Buy and Sell Stock iii
 * Hard
 * Jiawei Wang
 * 2021 7.27
 */

/* Revision 
 * $1 2021.9.10 Jiawei Wang
 */

/* #1 DP
 * What you do each day, only depends on 4 status yesterday:
 * for the ith day (i > 1):
 * 1) hold1_i: buy a stock on the ith day for the first time, or not. 
 * hold1_i => max(0 - prices[i], hold1_i-1)
 *
 * 2) sold1_i: sold a stock that we have yesterday for the first time, or not.
 * sold_i => max(hold_i-1 + prices[i], sold1_i-1)
 *
 * 3) hold2_i: buy a stock on the ith day for the second time, or not.
 * hold2_i => max(sold1_i-1 - prices[i], hold2_i-1)
 *
 * 4) sold2_i: sold a stock that we have for the second time, or not
 * sold2_i => max(hold2_i-1 + prices[i], sold2_i-1)
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 DP
    int maxProfit(vector<int>& prices) {
	int hold1 = INT_MIN, hold2 = INT_MIN;
	int sold1 = 0, sold2 = 0;

	for (auto p : prices) {
	    int hold1_tmp = hold1; // hold1_i-1
	    int hold2_tmp = hold2; // hold2_i-1
	    int sold1_tmp = sold1; // sold1_i-1
	    int sold2_tmp = sold2; // sold2_i-1

	    hold1 = max(0-p, hold1_tmp);
	    sold1 = max(hold1_tmp + p, sold1_tmp);
	    hold2 = max(sold1_tmp - p, hold2_tmp);
	    sold2 = max(hold2_tmp + p, sold2_tmp);
	}

	return max(sold1, sold2);
    }
};
