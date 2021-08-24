/*
 * LeetCode 139 Word Break
 * Medium
 * Jiawei Wang
 * 2021 8.24
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace::std;


// catsandog 
// cats dog sand and cat
//
// 1. dog + Break(catsan)
// 2. since catsan is not breakable return false
class Solution {
public:
    // DP (true and false)
    bool wordBreak(string s, vector<string>& wordDict) {
	// Key: the hole string s must be used, so we divide it
	// each compones must be divided into two parts:
	// | can1/cannot2 break  |  can1/cannot2 break  |
	// 1 + 1 return true
	// otherwise return false
	
	
	// Mark word in dict as breakable
	for (const string& word : wordDict) {
	    mem.emplace(word, true);
	}

	return Break(s);
    }

    // Recursion
    bool Break(const string& s) {

	// return whether s is in wordDict
	if (mem.count(s)) return mem[s]; // 


	// if s do not in wordDict, then we get the substr of s
	for (int j = 1; j < s.length(); j++) {
	    auto it = mem.find(s.substr(j)); // from j to the end

	    // if we get a substr which in wordDict
	    if (it != mem.end() && it->second && Break(s.substr(0, j))) return mem[s] = true;
	}

	return mem[s] = false; // this string are not breakable and just return false
	// since the s.substr(0, j) cannot be divided into words in wordDict
    }

private:
    unordered_map<string, bool> mem;
};

