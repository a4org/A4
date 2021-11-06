/*
 * LeetCode 136 Single Number
 * Easy
 * Shuo Feng
 * 2021.11.6
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution:
 *   a ⊕ 0 = a.
 *   a ⊕ a = 0;
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for (int num : nums) {
            n ^= num;
        }
        return n;
    }
};
