/*
 * LeetCode 40 Combination Sum ii
 * Medium
 * Jiawei Wang
 * 2021.9.30
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    // Combination --> Sequencial Arrangement
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<int> arrangement;
	vector<vector<int>> ans;
	sort(candidates.begin(), candidates.end());

	dfs(0, candidates, target, arrangement, ans);

	return ans;

    }

private:
    void dfs(int index, const vector<int> candidates, int target, vector<int> arrangement, vector<vector<int>>& unians) {
	if (target < 0) return;
	if (target == 0) {
	    // Termination Condition
	    unians.push_back(arrangement);
	    return;
	} 

	for (int i = index; i < candidates.size(); i++) {
	    if (i > index && candidates[i] == candidates[i-1]) continue;
	    // key: i > index means the first element cannot repeat

	    arrangement.push_back(candidates[i]);
	    dfs(i+1, candidates, target - candidates[i], arrangement, unians);
	    // BackTracking and i++ for another candidate
	    arrangement.pop_back();
	}

    }
};

