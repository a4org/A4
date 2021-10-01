/*
 * LeetCode 216 Combination Sum iii
 * Medium
 * Jiawei Wang
 * 2021.9.30
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // Just Like Previous i and ii 
    // DFS + BackTracking
    vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> ans;
	vector<int> combination;

	dfs(n, 1, k, combination, ans);
	
	return ans;
    }

private:
    void dfs(int n, int curri, int remain, vector<int> combination, vector<vector<int>>& ans) {
	// curri stands for next pick in [1, 9] (in sequence)
	// remain stands for the remaining number of size
	
	if (remain < 0) return;
	
	if (!remain && !n) {
	    // must k numbers
	    // Termination Condition
	    ans.push_back(combination);
	    return;
	} 

	for (int i = curri; i <= 9; i++) {
	    combination.push_back(i);
	    dfs(n - i, i + 1, remain - 1, combination, ans);
	    combination.pop_back();
	}
    }
};
