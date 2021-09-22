/*
 * LeetCode 26 Remove Duplicates from Sorted Array
 * Easy
 * Shuo Feng
 * 2021.9.22
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
 * Solution: Two pointers.
 *   Set two pointers, one of them point to number which is checking('slow'), the other one move backwards ('fast'),
 *   When 'fast' reach a number different from 'slow', change the number after 'slow' the same as what the 'fast' point to.
 *   Part beyond returned size do not need to consider.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        
        int fast = 1;
        int slow = 0;
        while (fast < size) {
            if (nums[fast] == nums[slow]) {
                fast += 1;
            }
            else {
                slow += 1;
                nums[slow] = nums[fast];
                fast += 1;
            }
        }
        return slow + 1;
    }
};
