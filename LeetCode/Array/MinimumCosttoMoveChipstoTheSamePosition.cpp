/*
 * LeetCode 1217 Minimum Cost to Move Chips to The Same Position.
 * Easy
 * Shuo Feng
 * 2021.12.6
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution:
 *   Since cost 0 when move two steps, so we should only consider the sum of chips on odd position or even position.
 */

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int size = position.size();
        int sum_odd  = 0;
        int sum_even = 0;

        for (int i = 0; i < size; ++i) {
            if (position[i] % 2)
                sum_even += 1;
            else
                sum_odd  += 1;
        }
        return min(sum_odd, sum_even);
    }
};
