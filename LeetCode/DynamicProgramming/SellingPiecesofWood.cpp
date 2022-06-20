/*
 * LeetCode 2312. Selling Pieces of Wood
 * Hard
 * Jiawei Wang
 * 2022.6.20
 */

#include <vector>

using namespace::std;
using LL = long long;

class Solution {
  LL dp[201][201];
public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    for (auto p : prices) {
      dp[p[0]][p[1]] = p[2];
    }

    // dp[i][j] stands for the maximum money you can earn after cutting an m x n piece of wood

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
	// for each size
	for (int k = 1; k < j; k++) {
	  // cutting vertically
	  dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j-k]);
	}

	for (int k = 1; k < i; k++) {
	  dp[i][j] = max(dp[i][j], dp[k][j] + dp[i-k][j]);
	}
      }
    }
    return dp[m][n];
  }
};

