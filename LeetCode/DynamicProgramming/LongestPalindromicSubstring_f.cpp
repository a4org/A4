/*
 * LeetCode 5 Longest Palindromic Substring
 * Medium
 * Shuo Feng
 * 2021.8.24
 * Last edited at 2021.9.23
 */

/*
 * Solution 1 dp
 *   Use dp[i][j] to stand the Relation between s[i] and s[j].
 *   Judge substring from short to long, move a window of determined length from left to right, and record palindromic substring.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) return s;

        int begin = 0;
        int max_length = 1;
        vector<vector<int>> dp(size, vector<int>(size, 0));

        for (int i = 0; i < size; ++i) {
            dp[i][i] = 1;
        }

        // Start with length 2 (at least 2 characters)
        for (int length = 2; length <= size; ++length) {
            
            for (int Left= 0; Left < size; ++Left) { // Left  point.
                int Right = length + Left - 1;       // Right point  (Right - Left + 1 = length).
                if (Right >= size) break;

                if (s[Left] == s[Right]) {
                     // length <= 3 (" bb " " bab ").
                    if (Right - Left + 1 <= 3) {
                        dp[Left][Right] = 1;
                    }
                    else
                        // According to the shorter substring between Left and Right.
                        dp[Left][Right] = dp[Left + 1][Right - 1];
                }
                else dp[Left][Right] = 0;

                // Update the maximum length.
                if ( dp[Left][Right] == 1 && max_length < Right - Left + 1) {
                    begin = Left;
                    max_length = Right - Left + 1;
                }
            }
        }
        return s.substr(begin, max_length);
    }
};
