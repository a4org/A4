/*
 * LeetCode 153 Find Minimum In Rotated Sorted Array
 * Medium
 * Jiawei Wang
 * 2021.10.23
 */


#include <vector>

using namespace::std;

class Solution {
public:
    // #1 O(n)
    // Avg -> logn
    int findMin1(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1]) return nums[i+1];
        }
        return nums[0];
    }


    // #2 O(logn) Binary Search
    int findMin2(vector<int>& nums) {
	// * > ###
	// * ** *** # ## ###
	int b = 0; int e = nums.size() - 1;

	while (b < e) {
	    if (nums[b] < nums[e]) return nums[b];

	    int mid = b + (e - b) / 2;
	    if (nums[b] <= nums[mid]) b = mid + 1;
	    else e = mid;
	}
	return nums[b];
    }
};

