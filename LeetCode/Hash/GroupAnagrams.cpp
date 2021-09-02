/*
 * LeetCode 49  Group Anagrams
 * Medium
 * Jiawei Wang
 * 2021 7.19
 */

/* Revision
 * $1 2021.9.2 Jiawei Wang
 * A very typical and pretty easy hash question
 * Use a Hash table store all sorted strings with its rearranging phase
 */

#include <vector> 
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> Map;

	for (int i = 0; i < strs.size(); i++) {
	    string t = strs[i];
	    sort(t.begin(), t.end());
	    Map[t].push_back(strs[i]);
	}

	vector<vector<string>> results;
	for (auto a : Map) {
	    results.push_back(a.second);
	}

	return results;
    } };
