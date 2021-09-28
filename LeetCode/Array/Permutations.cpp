/*
 * LeetCode 46 Premutations
 * Medium
 * Shuo Feng
 * 2021.9.28
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Backtracking.
 *   If nums = [1, 2, 3]
 *    
 *                        1                       2                       3            
 *                  /     |     \                ...                     ...
 *                 1      2      3
 *                /|\    /|\    /|\
 *               1 2 3  1 2 3  1 2 3
 *   Use a container to storage all numbers that have used, what we need to do is avoid using the number in container.
 */

class Solution {
private:
    vector<vector<int>> res;
    void findPermutations(vector<int>& nums, vector<int>& Permutation, vector<int>& Used) {
        if (Permutation.size() == nums.size()) {
            res.push_back(Permutation);
            return;
        }
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (!Used[i]) {
                    Permutation.push_back(nums[i]);
                    Used[i] = 1;
                    findPermutations(nums, Permutation, Used);

                    // Back tracking.
                    Permutation.pop_back();
                    Used[i] = 0; // Also update repeated number.
                }
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();

        vector<int> Permutation;
        // Numbers that have used.
        vector<int> Used(size, 0);
        findPermutations(nums, Permutation, Used);
        return res;
    }
};
