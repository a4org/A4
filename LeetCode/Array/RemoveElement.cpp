/*
 * LeetCode 27 Remove Element
 * Easy
 * Shuo Feng
 * 2021.9.22
 */

#include<iostream>
#include<vector>
using namespace std;

/* 
 * Solution : Two Pointers.
 *   Similar to LeetCode 26 Remove Duplicates from Sorted Array.
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int fast = 0;
        int slow = 0;

        while (fast < size) {
            if (nums[fast] != val) {
                //slow += 1;
                nums[slow] = nums[fast];
                slow += 1;
                fast += 1;
            }
            else {
                fast += 1;
            }
        }
        return slow;
    }
};

/*
 * or
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow += 1;
            }
        }
        return slow;
    }
};
