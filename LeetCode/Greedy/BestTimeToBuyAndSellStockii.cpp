/*
 * LeetCode 122 Best Time to Buy and Sell Stock ii
 * Medium
 * Jiawei Wang
 * 2021.9.10
 */

// Greedy

#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ret = 0;
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) ret += diff;
        }
        return ret;
    }
};
