/*
 * LeetCode 153 Find Minimum in Rotated Sorted Array
 * Medium
 * Shuo Feng
 * 2021.10.23
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Binary Search
 *   For a sorted array, if we rotate array, the array can be seen as the combination of two different sorted array,
 *  the leftmost side of the first array always bigger than the rightmost side of the second array.
 *
 *   Due to the array is sorted, we can consider of binary search.
 *   Compare right with mid, there`re two situation: (1). mid <  right, shorten the right (mid = right).
 *                                                   (2). mid >= right, the minimum is on mid`s right, shorten the left(left = mid + 1).
 *    
 *   Why fail if compare left with mid:
 *  consider of:        right -→ *                 *
 *                      mid -→ *         left -→ *
 *                           *                          * ←- right
 *                 left -→ *                          * ←- mid
 *
 *   Both two case are situation of (mid > left), but the scope of minimum is different.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        int right = size - 1;
        int left = 0;

        // If while(left <= right), when left = right it will loop again (run line 47), nums[left] will return false result.
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
              
                // mid < right, mid may be the minimum, skip mid is not allowed.
                right = mid;
            }
            else if (nums[mid] >= nums[right]) {
              
                // mid > right, mid can not be minimum, so we skip mid.
                left = mid + 1;
            }
        }
      
        // Or return nums[right]; 
        // After loop left = right.
        return nums[left];  
    }
};
