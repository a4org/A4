/*
 * LeetCode 448 Find All Numbers Disappeared in an Array
 * Easy
 * Shuo Feng
 * 2021.11.18
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution without extra space:
 *   Since 1 <= nums[i] <= n, traverse nums, add n to place 'nums[i]', after that if 'nums[i]' > n, number 'i' is appeared,
 *  if 'nums[i]' <= n, number 'i' is disappeared.
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            // Place begin with 0 -> nums[i] - 1.
            // Since duplication may exist, '%n' is necessary.
            int place = (nums[i] - 1) % n;
            nums[place] += n;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n)
                res.push_back(i + 1);
        }
        return res;
    }
};
