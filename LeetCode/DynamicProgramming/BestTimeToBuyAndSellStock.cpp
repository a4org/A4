/*
 * LeetCode 121  Best Time to Buy and Sell Stock
 * Easy
 * Jiawei Wang
 * 2021 7.26
 */

/* Revision
 * $1 2021.9.10 Jiawei Wang
 * For each days, you only have two options -- buy and sell
 * for the ith day
 * sell = max(sell, prices[i] - buy)
 * buy = min(buy, prices[i]);
 */

/* #1 Brute force:
 * Enumerate all possible cases, and find the maximum difference.
 * Time Complexity: O(n^2) TLE
 *
 * #2 DP
 * Keep tracking the lowest price and max profit sofar
 * lp[i] => lowest price up to i-th day
 * mp[i] => max profit up to i-day
 *
 * mp[i] = max(mp[i-1], price[i] - lp[i])
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;


class Solution {
public:
    // #1 Brute force
    int maxProfit1(vector<int>& prices) {
	vector<int> Diff;
	int n = prices.size();

	for (int i = 0; i < n; i++) {
	    for (int j = i; j < n; j++) {
		Diff.push_back(prices[j]-prices[i]);
	    }
	}
	auto ians = max_element(Diff.cbegin(), Diff.cend());
	int ans = *ians;
	return (ans > 0) ? ans : 0;
    }

    // #2 DP
    int maxProfit2(vector<int>& prices) {
	int n = prices.size();
	int lp[n];
	int mp[n];
	lp[0] = prices[0];
	mp[0] = 0;
	for (int i = 1; i < n; i++) {
	    lp[i] = ((prices[i] < lp[i-1]) ? prices[i] : lp[i-1]);
	    mp[i] = (max(mp[i-1], prices[i] - lp[i]));
	}
	return mp[n-1];
    }
    
    // #3 DP reduce storage
    int maxProfit3(vector<int>& prices) {
	int lp = INT_MAX, mp = 0;
	int lp_tmp, mp_tmp;
	for (auto p : prices) {
	    lp_tmp = lp;
	    mp_tmp = mp;
	    lp = min(lp_tmp, p);
	    mp = max(mp_tmp, p - lp);
	}
	return mp;
    }

    // #3 2021.9.10 redo Jiawei Wang
    int maxProfit4(vector<int>& prices) {
        int buy = prices[0];
        int sell = INT_MIN;
        int n = prices.size();
        
        for (int i = 1; i < n; i++) {
            int price = prices[i];
            sell = max(sell, price - buy);
            buy = min(prices[i], buy);
        }
        return max(0, sell);
    }
};



