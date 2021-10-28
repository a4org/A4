/*
 * LeetCode 15 3Sum
 * Medium
 * Shuo Feng
 * 2021.10.28
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * Solution: Double Pointers
 *   Select a number nums[i], check numbers after i.
 *   To find the numbers we want in a more accurate way, we can sort the array first, and search from two boundary after i.
 *  
 */

class Solution {
private:
    vector<vector<int>> res = {};

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; ++i) {
            int head = i + 1;
            int tail = size - 1;
          
            // Repeated -> skip.
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (head < tail) {
                int sum = nums[i] + nums[head] + nums[tail];

                // Exceed   -> reduce the maximum number (tail).
                if      (sum > 0) tail -= 1;
                // Shortage -> increase the minimum number(head).
                else if (sum < 0) head += 1;

                else if (sum == 0) {
                    res.push_back({ nums[i], nums[head], nums[tail] });
                  
                    // Line : Skip repeated numbers.
                    while (head < tail && nums[head] == nums[head + 1]) head += 1;
                    while (tail > head && nums[tail] == nums[tail - 1]) tail -= 1;
                    // Seach next number.
                    head += 1;
                    tail -= 1;
                }
            }
        }
        return res;
    }
};
