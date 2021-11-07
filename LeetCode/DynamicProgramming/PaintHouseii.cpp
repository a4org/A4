/*
 * LeetCode 265 Paint House ii
 * Hard
 * Jiawei Wang
 * 2021 11.7
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
	// pretty like 256
	// also the ith day only depends on the i-1th day
	// dp[i][k] -> choose color k in ith day
	
	int n = costs.size();
	if (n == 0) return 0;
	int k = costs[0].size();
	vector<int> dp(k+1, 0);

	for (int i = 0; i < k; i++) {
	    dp[i] = costs[0][i];
	}

	for (int i = 1; i < n; i++) {
	    vector<pair<int, int>> temp;
	    for (int l = 0; l < k; l++) {
		temp.push_back({dp[l], l});
	    }
	    sort(temp.begin(), temp.end()); // a reuse datastructure

	    for (int j = 0; j < k; j++) {
		// give k difference color a chance respectively
		if (j == temp[0].second) 
		    dp[j] = temp[1].first + costs[i][j];
		else
		    dp[j] = temp[0].first + costs[i][j];
	    }
	}
	int ret = INT_MAX / 2;
	for (int i = 0; i < k; i++) {
	    if (ret > dp[i]) ret = dp[i];
	}
	return ret;
    }
};

