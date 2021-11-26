/*
 * LeetCode 35 Search Insert Position
 * Easy
 * Jiawei Wang
 * 2021.11.26
 */

#include <vector>

using namespace::std;

// Binary Search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size();
        int mid = 0;
        while (beg < end) {
            mid = beg + (end-beg)/2; // left 
            if (nums[mid] < target) {
                beg = mid+1;
            } else if (nums[mid] > target) {
                end = mid;
            } else return mid;
        }
        return beg;
    }
};
