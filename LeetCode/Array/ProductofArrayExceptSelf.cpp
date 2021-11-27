/*
 * LeetCode 238 Product of Array Except Self
 * Medium
 * Shuo Feng
 * 2021.11.28
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution in O(n) time, without division operation.
 *   Traverse array twice, the first time traverse from left to right, add number to answer, and multiply the traversed numbers,
 *  in order to find the product of each elements` left.
 *   The second time traverse from right to left, in order to find the product of each elements` right.
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
      
        // From left to right.
        // Product of element`s left.
        int multi = 1;
        for (int i = 0; i < size; ++i) {
            ans[i] = multi;  // Add to ans.
            multi *= nums[i];
        }

        // From right to left.
        // Product of element`s right.
        multi = 1;   // Reset.
        for (int i = size - 1; i >= 0; --i) {
            ans[i] *= multi;  // Multiply ans
            multi *= nums[i];
        }
        return ans;
    }
};
