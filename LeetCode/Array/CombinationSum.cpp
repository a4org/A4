/*
 * LeetCode 39 Combination Sum
 * Medium
 * Shuo Feng
 * 2021.9.25
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Recursion Backtracking.
 */

class Solution {
public:
    vector<vector<int>> out_come; // Gather of combinations.
    vector<int> combination;      // Storage combination.
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findcombination(candidates, 0, target);
        return out_come;
    }

private:  
    void findcombination(vector<int>& candidates, int level, int target) {
        int size = candidates.size();
        if (level == size) return;

        // Push combination in out_come
        if (target == 0) {
            out_come.push_back(combination);
            return;
        }

        for (int i = level; i < size; ++i) {
            if (target - candidates[i] >= 0) {
                combination.push_back(candidates[i]);
                // Number in candidates can be used in unlimited number of times, the next level is i. 
                findcombination(candidates, i, target - candidates[i]);
                // Backtracking.
                combination.pop_back();
            }
        }
    }
};
