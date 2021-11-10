/*
 * LeetCode 121 Best Time to Buy And Sell Stock 
 * Easy
 * Shuo Feng
 * 2021.11.10
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution:
 *   maxPro: the maximum profit we can earn.
 *   minprices: the minimum prices before day i.
 *
 *   Traverse 'prices' once, record the minimum prices before day i, the max profit in day i: 'prices[i] - minprices'
 *  compare all possible solution, find the most ideal one.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        int maxPro = 0;
        int minprices = INT_MAX;

        for (int i = 0; i < days; ++i) {
            maxPro = max(maxPro, prices[i] - minprices);
            minprices = min(minprices, prices[i]);
        }

        return maxPro;
    }
};

