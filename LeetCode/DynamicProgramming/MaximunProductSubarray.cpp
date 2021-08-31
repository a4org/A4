/*
 * LeetCode 152 Maximum Product Subarray
 * Medium
 * Shuo Feng
 * 2021.8.31
 */

/*
 * Solution Dp:
 *   Maintain two values: "Max" and "Min", "Max" is used to record the maximum value strat with place i, 
 *  and "Min" is used to record the minimum value.
 *   The reason why record the minimum value: 
 *   When meet a negative number, the maximum one and the minimum one will replace.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 0) return 0;
       
        int Max_product = INT_MIN;
        int Max = 1;
        int Min = 1;

        for (int i = 0; i < size; ++i) {
                               
            int Max_2 = Max;  // Record current value, "Max" will change at line 
          
            // Besides choose the maximum / minimum one,  each time compare with the "Min" (Min * nums[i])
            Max = max(max(Max * nums[i], nums[i]), Min * nums[i]);
            Min = min(min(Max_2 * nums[i], nums[i]), Min * nums[i]);

            Max_product = max(Max_product, Max);
        }
        return Max_product;

    }
};
