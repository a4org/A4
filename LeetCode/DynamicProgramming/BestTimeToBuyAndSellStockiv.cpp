/*
 * LeetCode 188  Best Time to Buy and Sell Stock iv
 * Hard
 * Jiawei Wang
 * 2021 7.27
 */

/* Revision
 * $1 2021.9.11 Jiawei Wang
 * Think more, but do not spend too much time on it. 
 * Key(How to?): Do it when you are in a good state.
 */

/* #1 DP 
 * Build two dp tables: sold[i][k] and hold[i][k]
 *
 * on the i-th day, with k-th time solding/holding stock.
 * sold[i][k]: sell a stock on the i-th day for the k-th time or not
 * => max(sold[i-1][k], hold[i-1][k] + prices[i])
 *
 * hold[i][k]: hold a stock on the i-th day for the k-th time or not
 * => max(hold[i-1][k], sold[i-1][k-1] - prices[i])
 */

#include <vector>

using namespace::std;


class Solution {
public:
    // #1 DP
    int maxProfit1(int k, vector<int>& prices) {
	int n = prices.size();

	if (k >= n/2) {
	    // like 122 Best Time to Buy and Sell Stock ii (greedy)
	    int result = 0;
	    for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i-1]) result += prices[i] - prices[i-1];
	    }
	    return result;
	}

	vector<int>hold(k+1, INT_MIN/2);  // avoid overflow
	vector<int>sold(k+1, INT_MIN/2);

	hold[0] = 0; sold[0] = 0;

	for (int i = 0; i < n; i++) {
	    // like 123 Best Time to Buy and Sell Stock iii (DP)
	    // for the i-th day
	    // consider all cases
	    auto hold_old = hold;
	    auto sold_old = sold;
	    // we do not need to use O(n^2 Space) with two dp[i][k] tables
	    for (int j=1; j<=k; j++) {
		// assume the ith day with k-th time holding/solding stock
		// with k status
		hold[j] = max(sold_old[j-1] - prices[i], hold_old[j]); 
		sold[j] = max(hold_old[j] + prices[i], sold_old[j]); // Note hold_old[j] + prices[i]

	}
	int result = INT_MIN;
	for (int j = 0; j <= k; j++) {
	    result = max(result, sold[j]);
	}
	return result;
    }
};
