/*
 * LeetCode 33 Search in Rotated Sorted Array
 * Medium
 * Shuo Feng
 * 2021.9.23
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Binary Search
 *   When search in sorted array, always consider binary search.
 *   Some differences： After rotated, the new array is a combination of two different sorted array, we should find the side
 *  where target is according to boundary value (Noticed that if " nums[mid] > target ", both two sides are possible).
 *
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0, mid, high = size - 1;
        // Recode the result.
        int flag = -1;

        while (high >= low) {
            mid = (high + low) / 2;

            // Find target.
            if (nums[mid] == target) {
                flag = mid;
                break;
            }
          
            // On mid `s left is ordered.
            if (nums[mid] >= nums[0]) {
                // Target located on mid `s left.
                if (target < nums[mid] && target >= nums[0])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            
            // On mid `s right is ordered.
            else {
                // Target located on mid `s right.
                if (target > nums[mid] && target <= nums[size - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return flag;
    }
};
