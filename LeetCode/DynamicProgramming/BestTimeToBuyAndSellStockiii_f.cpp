/*
 * LeetCode 123 Best time To Buy And Sell Stock iii
 * Hard
 * Shuo Feng
 * 2021.10.16
 */

/*
 * Solution 1: Dp
 *   Describe each days by four status (more detail at line 36 ).
 *
 *   For day i, (1) if buy a stock for the first time, we can earn: ' 0 - prices[i] ', 
  *                 else the profit is same as before.
 *
 *              (2) if sell a stock for the first time, we can earn: ' buy_1 + prices[i] ',
 *                  else ...
 *
 *              (3) if buy a stock for the second time, we can earn: ' sell_1 - prices[i] ', (basic on the profit we get after sell a stock).
 *                  ...
 *
 *              (4) if sell a stock for the second time, we can earn: ' buy_2 + prices[i] ',
 *                  ... 
 *
 *   Judge each days` profit depend on situations before, in the end we should only consider the profit after sell stock.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        // Each days the maximum profit we can get with four situation.
        // Situation of the first day.
        int buy_1 = -prices[0]; // The first  time to buy.
        int buy_2 = -prices[0]; // The second time to buy.
        int sell_1 = 0;         // The first  time to sell.
        int sell_2 = 0;         // The Second time to sell.

        for (int i = 1; i < days; ++i) {
            // Update profit for day i.
            buy_1  = max(buy_1  ,      0 - prices[i]);
            sell_1 = max(sell_1 , buy_1  + prices[i]);
            buy_2  = max(buy_2  , sell_1 - prices[i]);
            sell_2 = max(sell_2 , buy_2  + prices[i]);
        }
        return max(sell_1, sell_2);
    }
};
