/*
 * LeetCode 120 Triangle
 * Medium
 * Jiawei Wang
 * 2021 9.3
 */

#include <algorithm>
#include <vector>

using namespace::std;


/*
 * Thinking question in a simple way
 * [[2]
 *  [3, 4]
 *  [5, 6, 7]
 *  [8, 9, 10, 11]]
 */

class Solution {
public:
    // #1 DP (Classic)
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
    int minimumTotal1(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); 
	// dp[i][j] represents the minimum number if we choose triangle[i][j] in layer i
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= i; j++) {
		dp[i][j] = triangle[i][j];
		// Boundary conditions
		if (i == 0 && j == 0) continue;
		if (j == 0) dp[i][j] += dp[i-1][j]; // first element of the line
		else if (i == j) dp[i][j] += dp[i-1][j-1]; // end of the line

		else  dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
	    }
	}
	return *min_element(dp[n-1].cbegin(), dp[n-1].cend());
    }

    // #1.5 DP with less Space Complexity O(n)
    int minimumTotal15(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<vector<int>> dp(2, vector<int>(n, INT_MAX)); 
	// we only need two vectors one for current layer, one for previous layer
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= i; j++) {
		dp[1][j] = triangle[i][j];
		// Boundary conditions
		if (i == 0 && j == 0) continue;
		if (j == 0) dp[1][j] += dp[0][j]; // first element of the line
		else if (i == j) dp[1][j] += dp[0][j-1]; // end of the line

		else  dp[1][j] += min(dp[0][j-1], dp[0][j]);
	    }
	    swap(dp[0], dp[1]);
	}
	return *min_element(dp[0].cbegin(), dp[0].cend());
    }

    // #2 DP with no extre space
    int minimumTotal2(vector<vector<int>>& t) {
	for (int i = 0; i < t.size(); i++) 
	    for (int j = 0; j <= i; j++) {
		// Boundary Conditions
		if (i == 0 && j == 0) continue;
		if (j == 0) t[i][j] += t[i-1][j];
		else if (i == j) t[i][j] += t[i-1][j-1];

		else t[i][j] += min(t[i-1][j-1], t[i-1][j]);
	    }

	return *min_element(begin(t.back()), end(t.back()));
    }
};


