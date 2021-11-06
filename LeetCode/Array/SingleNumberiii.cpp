/*
 * LeetCode 260 Single Number iii
 * Medium
 * Shuo Feng
 * 2021.11.6
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * Solution 1: Hash Table
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) return nums;

        vector<int> res;
        unordered_map<int, int> freq;
        for (int i = 0; i < size; ++i) {
            freq[nums[i]] += 1;
        }

        for (auto [num, times] : freq) {
            if (times == 1)
                res.push_back(num);

            if (res.size() == 2)
                break;
        }
        return res;
    }
};

/*
 * Solution 2: ^
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long diff = 0;
        for (int num : nums) {
            diff ^= num;
        }

        int rightmost = diff & (-diff);
        int n1 = 0;
        int n2 = 0;

        for (int num : nums) {
            if (num & rightmost)
                n1 ^= num;

            else
                n2 ^= num;
        }
        return { n1, n2 };
    }
};
