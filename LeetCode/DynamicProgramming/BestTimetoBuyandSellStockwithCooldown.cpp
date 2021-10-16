/*
 * LeetCode 309 Best Time to Buy and Sell Stock with Cooldown
 * Medium
 * Shuo Feng
 * 2021.10.15
 * Last edited at 2021.10.16
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution 1: dp
 *   Use array: dp to storage the maximum profit we can get until days i, see more details at line 53
 *   For days i(i>0), we should judge profit acording to situations before, there`re three cases:
 *
 *     I.   Do not own in day i(dp[i][0]):  (1) own non in day 'i-1'.
 *                                          (2) sell stock in day 'i-1'.  (line 46)
 *
 *     II.  Own stock in day i(dp[i][1]):   (1) own stock in day 'i-1'.
 *                                          (2) buy stock in day 'i'.     (line 47)
 *
 *     III. Own and sell stock in day i(dp[i][2]):  earn 'prices[i]'.     (line 48)
 *
 *     Just find the way to get maximum profit.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        // The maximum profit we can achieve until days i in three cases.
        vector<vector<int>> dp(days, vector<int>(3, 0));
        // Three options:
        // dp[i][0] : own no stock.
        // dp[i][1] : own stock.
        // dp[i][2] : own and sell.

        // Beginning situations.
        dp[0][0] = 0;
        dp[0][1] = prices[0] * -1; // Owe.
        dp[0][2] = 0;

        for (int i = 1; i < days; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }

        return max(max(dp[days - 1][0], dp[days - 1][1]), dp[days - 1][2]);
    }
};


/*
 * Solution 1.5 Dp
 *   Describe the maximum prodit by three status:
 *     buy:  buy a stock.
 *     sell: sell a stock.
 *     cool: the day after selling a stock
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        int buy = 0 - prices[0];
        int sell = 0;
        int cool = 0;

        for (int i = 1; i < days; ++i) {
            // Record the status of day i-1.
            int buy_2 = buy;
            int sell_2 = sell;
            int cool_2 = cool;

            // Update 
            buy  = max(buy_2 , cool_2 - prices[i]);
            sell = max(buy_2 , buy_2  + prices[i]);
            cool = max(cool_2, sell_2);
        }
        return sell // Only think about sell.
    }
};
