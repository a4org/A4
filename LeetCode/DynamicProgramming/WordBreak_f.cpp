/*
 * LeetCode 139 Work Break
 * Medium
 * Shuo Feng
 * 2021.8.27 
 */

/*
 * Solution : Dp
 *   " dp[i] " stand whether the first i letters can be segmented into one or more dictionary words.
 *  
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (const string& word : wordDict) {
            mem.emplace(word, true);
        }
        int size = s.size();
        vector<int> dp(size + 1, 0)；
        dp[0] = 1;  // Starting conditions
        
        // For faster speed, find the maximum and minimum length, and we can get the better starting place.
        int maxlen = 0;
        int minlen = INT_MAX;
        for (auto word : wordDict) {
            int size_2 = word.size();
            maxlen = max(maxlen, size_2);
            minlen = min(minlen, size_2);
        }
        // From starting point, search the interval before it.
        for (int i = minlen; i <= size; ++i) {
            
          // Space before i should be bigger than the maximum length, otherwise start with " 0 ".
            for (int j = max(i - maxlen, 0); j < i; ++j) {
                if (dp[j] && mem.find(s.substr(j, i - j)) != mem.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[size];
    }

private:
    unordered_map<string, bool> mem;
};
