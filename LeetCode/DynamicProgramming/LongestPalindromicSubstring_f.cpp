/*
 * LeetCode 5 Longest Palindromic Substring
 * Medium
 * Shuo Feng
 * 2021.8.24
 */

/*
 * Solution 1 dp
 * 
 * Use dp[i][j] to stand the Relation between s[i] and s[j].
 * 
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

        for (int length = 2; length <= size; ++length) {
            for (int L = 0; L < size; ++L) {  // left starting point.
                int R = length + L - 1;       // right point  ( R- L+ 1 = length ).
                if (R >= size) break;

                if (s[L] == s[R]) {
                    //length <= 3 (" bb " " bab ").
                    if (R - L + 1 <= 3) { 
                        dp[L][R] = 1;
                    }  
                    else
                        dp[L][R] = dp[L + 1][R - 1];
                }
                else dp[L][R] = 0;
                
                // Search the longest one.
                if (dp[L][R] == 1 && max_length < R - L + 1) {
                    begin = L;
                    max_length = R - L + 1;
                }
            }
        }
        return s.substr(begin, max_length);
    }
};

