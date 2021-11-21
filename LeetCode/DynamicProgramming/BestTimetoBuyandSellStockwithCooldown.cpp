/*
 * LeetCode 309  Best Time to Buy and Sell Stock with Cooldown
 * Medium
 * Jiawei Wang
 * 2021 7.27
 */


/* #1 DP
 * DP -- list all possible cases per day
 *
 * hold : buy a stock
 * => max(hold_old, cooled_old - p)
 *
 * sold : sell a stock
 * => hold_old + p
 *
 * cooled : the next day after selling a stock 
 * => max(cooled_old, sold_old)
 */

/* Revision
 * $1 2021.9.11 Jiawei Wang
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int hold = INT_MIN, sold = 0, cooled = 0;
	for (int i = 0; i < prices.size(); i++) {

	    int hold2 = hold, sold2 = sold, cooled2 = cooled;
	    int p = prices[i];

	    hold = max(hold2, cooled2-p); // hold can only comes from cooled2(that's key)
	    sold = hold2 + p;
	    cooled = max(cooled2, sold2);
	}
	return max(sold, cooled);
};
