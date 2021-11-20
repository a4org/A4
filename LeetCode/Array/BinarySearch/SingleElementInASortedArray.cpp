/*
 * LeetCode 540 Single Element in a Sorted Array
 * Medium
 * Jiawei Wang
 * 2021.11.20
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Sorted -> O(logn) -> Binary Search
        // odd / even
        
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int beg = 0, end = n-1;
        int mid = 0;
        while (beg < end) { // != 
            mid = beg + (end-beg)/2; // left
            if (nums[mid] == nums[mid-1]) {
                if ((end-mid) % 2 == 0) { // 0 to mid-2
                    end = mid - 2;
                } else {
                    beg = mid + 1;
                }
            }
            else if (nums[mid] == nums[mid+1]) { 
                if ((end-mid) % 2 == 0) {
                    // on the right
                    beg = mid + 2;
                } else {
                    end = mid - 1;
                }
                
            }
            else return nums[mid];
        }
        return nums[beg];
    }
};
