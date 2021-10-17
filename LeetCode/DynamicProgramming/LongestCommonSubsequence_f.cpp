/*
 * LeetCode 1143 Longest Common Subsequence
 * Medium
 * Shuo Feng
 * 2021.10.17
 */

/*
 * Solution 1: Dp
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size_1 = text1.size();
        int size_2 = text2.size();

        if (size_1 == 0 || size_2 == 0) return 0;

        // Longest subsequence between text1[0 ~ i - 1], text2[0 ~ j - 1].
        vector<vector<int>> dp(size_1 + 1, vector<int>(size_2 + 1, 0));

        for (int i = 1; i <= size_1; ++i) {
            for (int j = 1; j <= size_2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                  
                    // Add length on the basic of shorter sequence.
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // Return the longest subsequence between text1[0 ~ size1 - 1] and text2[0 ~ size2 - 1];
        return dp[size_1][size_2];
    }
};
