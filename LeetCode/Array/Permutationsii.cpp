/*
 * LeetCode 47 Permutations ii
 * Medium
 * Shuo Feng
 * 2021.9.29
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * Solution: Backtracking
 *   On the Basic of LeetCode 46 Permutations, add situation of repeated number in "nums".
 *   To avoid duplicate results, we can sort "nums", when creat a conbination we need to avoid numbers that have used.
 *   (The difference: do not use repeated numbers in each level.)
 */

class Solution {
private:
    vector<vector<int>> res;
    void findpermutations(vector<int>& nums, vector<int>Permutations, vector<int> used) {
        if (Permutations.size() == nums.size()) {
            res.push_back(Permutations);
            return;
        }
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (used[i])
                    continue;
              
                // Condition to skip.
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;

                Permutations.push_back(nums[i]);
                used[i] = 1;
                findpermutations(nums, Permutations, used);

                // Back trackng
                Permutations.pop_back();
                used[i] = 0;

            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        vector<int> Permutations;
        vector<int> used(size, 0);

        // Sort the nums, to find used number more effective.
        sort(nums.begin(), nums.end());
        findpermutations(nums, Permutations, used);
        return res;
    }
};
