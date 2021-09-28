/*
 * LeetCode 77 Combinations
 * Medium
 * Jiawei Wang
 * 2021.9.28
 */

#include <vector>

using namespace::std;

class Solution {
    vector<vector<int>> ans;
public:
    // #1 Recursion (DFS and BackTracking)
    // Key: we keep the vector increasing to reduce the complexity
    vector<vector<int>> combine(int n, int k) {
	vector<int> combo;
	dfs(n, k, 1, combo);
	return ans;
    }

    
    // #2 A tricky But very fast solution:
    vector<vector<int>> combine2(int n, int k) {
	vector<int> combo;

	for (int i = 1; i <= k; i++) {
	    combo.push_back(i); // 1 2 3 4 5
	}
	ans.push_back(combo);

	while (1) {
	    int i = k - 1; // index = size - 1 (the last element)
	    while (i >= 0 && combo[i] == i + 1 + n - k) i--; // find the maximum index we can deal with
		// (n - k) represents the maximum adding range
		// e.g., n = 7  k = 5 
		// 1 2 3 4 5
		// 1 2 3 4 6
		// 1 2 3 4 7
		// 1 2 3 5 6
		// 1 2 3 5 7
		// 1 2 3 6 7
		// 1 2 4 5 6
		// ...
	    // combo[2] <= 2 + 1 + 2 = 5

	    if (i == -1) break; // Exit

	    combo[i]++;
	    for (int j = i + 1; j < k; j++) {
		combo[j] = combo[j-1] + 1;
	    }

	    ans.push_back(combo);

	}
	return ans;
    }

private:
    void dfs(int n, int k, int curr, vector<int>& combo) {
	if (combo.size() == k) {
	    // Terminate Condition
	    ans.push_back(combo);
	    return;
	} 

	for (int i = curr; i <= n; i++) {
	    combo.push_back(i);
	    dfs(n, k, i+1, combo);
	    // Next start point
	    combo.pop_back();
	}
    }
};

