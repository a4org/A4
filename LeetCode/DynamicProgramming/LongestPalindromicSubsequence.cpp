/*
 * LeetCode 516  Longest Palindromic Subsequence
 * Medium
 * Jiawei Wang
 * 2021 7.20
 */


/* #1 DP
 * dp[i][j] stands for the longest palindromic subsequence between string[i] and string[j]
 *
 * example:
 * string a g b d b a
 * lps =  abdba 
 * ans =  5
 *
 * dp table:
 *
 * -------------------------------
 * |     (1)  (2)  (3)  (4)  (5) |
 * | (1)  1    1    1    3    5  |   
 * |                             |
 * | (2)  0    1    1    3    3  |
 * |                             |
 * | (3)  0    0    1    3    3  |
 * |                             |
 * | (4)  0    0    1    1    1  |
 * |                             |
 * | (5)  0    0    0    0    1  |
 * -------------------------------
 */

/* Revision
 * $1 2021.9.8 Jiawei Wang
 * case#1: s[i] == s[j]
 * a*****a -> dp[i][j] 
 *	    = dp[i+1][j-1] + 2
 * case#2: s[i] != s[j] pick the max of following #1 and #2:
 * #1 ab*****b dp[i][j] = dp[i+1][j]
 *     |     |
 * #2 a*****ab dp[i][j] = dp[i][j-1]
 *    |     |
 *
 * key: if s[i] != s[j]: dp[i][j] is not related to dp[i+1][j-1] (0)
 */

#include <vector>
#include <string>

using namespace::std;

class Solution {
    public:
	int longestPalindromeSubseq(string s) {
	    int N = s.size();
	    s = "#" + s;
	    auto dp = vector<vector<int>>(N+1, vector<int>(N+1, 0));

	    for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;  // the lps of any char is 1
	    }

	    for (int len = 2; len <= N; len++) {
		for (int i = 1; i+len-1 <= N; i++) {
		    int j = i + len - 1;
		    if (s[i] == s[j]) 
			dp[i][j] = dp[i+1][j-1] + 2;
		    else 
			// just see
			dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
		}
	    }
	    return dp[1][N];
	}
};
