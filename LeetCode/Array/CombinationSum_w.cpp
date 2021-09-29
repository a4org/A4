/*
 * LeetCode 39 Combination Sum
 * Medium
 * Jiawei Wang
 * 2021.9.29
 */

// Like LeetCode 77 Combinations
// Simple BackTracking DFS

#include <vector>

using namespace::std;

class Solution {
public:
    // Combination --> Sequencial Arrangement
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<int> arrangement;
	vector<vector<int>> ans;
	dfs(0, candidates, target, arrangement, ans);

	return ans;

    }

private:
    void dfs(int index, const vector<int> candidates, int target, vector<int> arrangement, vector<vector<int>>& ans) {
	if (target == 0) {
	    // Termination Condition
	    ans.push_back(arrangement);
	    return;
	} else {
	    for (int i = index; i < candidates.size(); i++) {
		if (target - candidates[i] >= 0) {
		    arrangement.push_back(candidates[i]);
		    dfs(i, candidates, target - candidates[i], arrangement, ans);
		    // BackTracking and i++ for another candidate
		    arrangement.pop_back();
		}
	    }
	}

    }
};

