/* 
 * LeetCode 721 Accounts Merge
 * Medium
 * Jiawei Wang
 * 2021.11.29
 */

#include <unordered_map>
#include <string>
#include <vector>
#include <set>

using namespace::std;

class Solution {
    unordered_map<string, string> Father;     // Email -> Name
    unordered_map<string, string> Owner; 
    unordered_map<string, set<string>> Group; // Name -> [Emails]

public:
    vector<vector<string>> accountMerge(vector<vector<string>>& accounts) {
	// Build table
	for (int i = 0; i < accounts.size(); i++) {
	    for (int j = 1; j < accounts[i].size(); j++) {
		Father[accounts[i][j]] = accounts[i][j];
		Owner[accounts[i][j]] = accounts[i][0];
	    }
	}

	for (int i = 0; i < accounts.size(); i++) {
	    for (int j = 2; j < accounts[i].size(); j++) {
		if (FindFather(accounts[i][j]) != FindFather(accounts[i][j-1])) {
		    // Union the hole group
		    Union(accounts[i][j], accounts[i][j-1]);
		}
	    }
	}


	// Actual things
	for (int i = 0; i < accounts.size(); i++) {
	    for (int j = 1; j < accounts[i].size(); j++) {
		string parent = FindFather(accounts[i][j]);
		Group[parent].insert(accounts[i][j]);
	    }
	}

	// Build the ans
	vector<vector<string>> ret;
	for (auto a : Group) {
	    vector<string> temp;
	    temp.push_back(Owner[a.first]);
	    for (auto b : a.second) temp.push_back(b);


	    ret.push_back(temp);
	}

	return ret;
    }

private:
    string FindFather(string x) {
	// iteration
	if (Father[x] != x) {
	    Father[x] = FindFather(Father[x]);
	}
	return Father[x];
    }

    void Union(string x, string y) {
	// Father[x] = Father[y] = Min(Father[x], Father[y])
	x = Father[x];
	y = Father[y];
	if (x < y) Father[y] = x;
	else Father[x] = y;
    }


};
