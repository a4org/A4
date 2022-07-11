/*
 * LeetCode 2222 Number of Ways to Select Buildings
 * Medium
 * Jiawei Wang
 * 2022.7.10
 */

#include <string>

using namespace::std;
using LL = long long;

class Solution {
  LL dp[100001][4][2];
  // dp[i][j][k] := we are now in index i
  // with #j buildings selected and last with k
public:
  long long numberOfWays(string s) {
    const int len = s.size();

    s = '#' + s;

    // begins
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for (int i = 1; i <= len; i++) {
      for (int j = 0; j <= 3; j++) {
	for (int k = 0; k < 2; k++) {

	  dp[i][j][k] = dp[i-1][j][k]; // we do not pick this one

	  if (j >= 1 && s[i]-'0' == k) {
	    // try to pick this one
	    dp[i][j][k] += dp[i-1][j-1][1-k];
	  }
	}
      }
    }

    return dp[len][3][0] + dp[len][3][1];
  } 
};
