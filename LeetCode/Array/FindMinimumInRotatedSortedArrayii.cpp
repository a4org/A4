/*
 * LeetCode 154 Find Minimum In Rotated Sorted Array ii
 * Hard
 * Shuo Feng
 * 2021.20.23
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Binary Search
 *   ★ More detial at FindMinimumInRotatedSortedArray.cpp (LeetCode 153)
 *
 *   Different with LeetCode 153, now we may meet the situation of mid = right, 
 *  on the basic of 153, when mid = right, just move right boundary to the left (right --), 
 *  the minimum always between [left, right - 1], so ingore right number, 
 *  if right is the minimum, we can still substitute right with mid (return minimum number but not where it is).
 *   
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        int left = 0;
        int right = size - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            }

            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // mid == right
            else {
                right -= 1;
            }
        }
        return nums[left];
    }
};
