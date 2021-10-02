/*
 * LeetCode 1143 Longest Common Subsequence
 * Medium
 * Jiawei Wang
 * 2021 10.2
 */


#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    // #1 Classic DP
    int longestCommonSubsequence(string text1, string text2) {
	int n1 = text1.size();
	int n2 = text2.size();

	if (n1 == 0 || n2 == 0) return 0;

	vector<vector<int>> dp(n1+1, vector<int>(n2+1));
	// dp[i][j] -> the lcs of text1[0, i] and text2[0, j]
        
	for(int i = 0; i < n1; i++) {
	    for (int j = 0; j < n2; j++) {
		if (text1[i] == text2[j]) {
		    dp[i+1][j+1] = dp[i][j] + 1;
		} else {
		    // dp[i+1][j+1] is the max of two prev 
		    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	    }
	}
	return dp[n1][n2];
    }
    

    // #2 Optimized Storiage DP
    int longestCommonSubsequence2(string text1, string text2) {
	int n1 = text1.size();
	int n2 = text2.size();

	if (n1 == 0 || n2 == 0) return 0;
	vector<int> dp(n2 + 1); // dp[i] stands for the lcs of text2[0, i]

	for (int i = 0; i < n1; i++) {
	    int prev = 0; // dp[i][j] in #1
	    for (int j = 0; j < n2; j++) {
		// deal with i + 1
		int curr = dp[j+1]; // dp[i][j+1] in #1

		if (text1[i] == text2[j]) {
		    dp[j+1] = prev + 1; // dp[i][j] + 1
		} else {
		    dp[j+1] = max(curr, dp[j]);
		}
		prev = curr;
	    }
	}
	return dp[n2];
    }
};

