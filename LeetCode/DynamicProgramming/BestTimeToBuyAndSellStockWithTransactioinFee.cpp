/*
 * LeetCode 714  Best Time to Buy and Sell Stock with Transaction Fee
 * Medium
 * Jiawei Wang
 * 2021 7.27
 */

/* 
 * #1 DP
 * Unlike LeetCode #122 it should balance the number of transaction fee
 *
 * status:
 * sold => max(sold_old, hold_old + p - fee)
 * hold => max(hold_old, sold_old - p)
 *
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
	int sold = 0;
	int hold = INT_MIN/2;

	for (auto p : prices) {
	    int sold_old = sold;
	    int hold_old = hold;

	    sold = max(sold_old, hold_old + p - fee);
	    hold = max(hold_old, sold_old - p);
	}
	return sold;
    }
};

