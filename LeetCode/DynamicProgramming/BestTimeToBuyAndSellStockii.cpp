/*
 * LeetCode 122 Best time to Buy And Sell Stock ii 
 * Medium
 * Shuo Feng
 * 2021.11.10
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution 1: Dp
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        // The maximum profit we can get in day i with two situations:
        vector<vector<int>> dp(days, vector<int>(2, 0));
        // In days i:
        // dp[i][0] : own no stock.
        // dp[i][1] : own stock.

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < days; ++i) {
            // Two situations in day i 
            //    I.  own no stock: (1) own no stock in day i - 1.
            //                      (2) sell in day i - 1.
            //
            //    II. own stock: (1) own in day i - 1.
            //                   (2) buy a stock in day i - 1.
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
      
        // Always earn the most after sell all stock.
        return dp[days - 1][0];
    }
};


/*
 * Solution 1.5: Dp  Optimize on the basis of solution 1.
 *   no:   own no stock. (correspond dp[i][0] in solution 1.)
 *   hold: own a stock.  (correspond dp[i][1] in solution 1.)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        // Day 1:
        int no = 0; 
        int hold = -prices[0];         

        for (int i = 1; i < days; ++i) {
            no    = max (no, hold + prices[i]);
            hold  = max (hold, no - prices[i]);
        }
        return no;
    }
};


/*
 * Solution 2: Greedy.
 *   Sell Stock whenever we can earn.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();

        int maxPro = 0;
        for (int i = 1; i < days; ++i) {
            if (prices[i] > prices[i - 1]) {
                maxPro += prices[i] - prices[i - 1];
            }
        }

        return maxPro;
    }
};
