/*
 * LeetCode 140 Word Break ii
 * Hard
 * Jiawei Wang
 * 2021 8.24
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    // DP Hash table 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());

        return wordBreak(s, dict);
    }
private:
    // >> append({"cats and", "cat sand"}, "dog");
    // {"cats and dog", "cat sand dog"}
    vector<string> append(const vector<string>& prefixes, const string& word) {
        vector<string> results;
        for (const auto& prefix : prefixes)
            results.push_back(prefix + " " + word);
        return results;
    }
    
    // key function
    const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
	// like LC139, we break s into two pieces

        // Already in memory, return directly
        if (mem_.count(s)) return mem_[s];
        
        // Answer for s
        vector<string> ans;
        
        // s in dict, add it to the answer array
	// then at the end of this function, we return the ans
        if (dict.count(s)) 
            ans.push_back(s);
        
        for (int j = 1; j < s.length(); ++j) {
	    // for each child string (layer)
	    // we caculated all possible cases (substrings)
	    
            // Check whether right part is a word
	    // every vector<string> of left will add right
            const string& right = s.substr(j);
            if (!dict.count(right)) continue;
            
	    // right part is a word
            // Get the ans for left part
            const string& left = s.substr(0, j);
            const vector<string> left_ans = append(wordBreak(left, dict), right);
            
            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
	    // ans contains all left_ans
        }
        
        // memorize and return
        mem_[s].swap(ans);
        return mem_[s];
    }
private:
    unordered_map<string, vector<string>> mem_; // Key to understand:
    // mem_[s] contains all possible word breaks of s
    // For example:
    // mem_["catsand"] = ["cat sand", "cats and"]
};
