/*
 * LeetCode 75 Sort Colors
 * Medium
 * Shuo Feng
 * 2021.10.27
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Double pointers
 *   Since there`re only three colors, when reach red, put it in head and if reach blue, just put it in tail.
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();

        int head = 0;        // Head place.
        int tail = size - 1; // Tail place.
        int check = 0;       // Place to check.

        while (check <= tail) {
          
            // If white(1), skip and turn to next color.
            if (nums[check] == 1)
                check += 1;

            // If red(0), swap it with head.
            else if (nums[check] == 0) {
                swap(nums[head], nums[check]);
                head += 1;  // nums[check] has been checked, move head.
                check += 1; // Head place has been checked, move 'check' to next place.
            }

            // If blue(2), swap it with tail.
            else if (nums[check] == 2) {
                swap(nums[tail], nums[check]);
                tail -= 1;  // Tail place has not yet been checked, only move tail.
            }
        }
        return;
    }
};
