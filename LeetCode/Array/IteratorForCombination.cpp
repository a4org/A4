/*
 * LeetCode 1286 Iterator for Combination
 * Medium
 * Jiawei Wang
 * 2021.12.11
 */

#include <string>
#include <vector>
#include <iostream>

using namespace::std;

class CombinationIterator {

public:
    CombinationIterator(string characters, int combinationLength) {
	this->ans = staticComb(characters, combinationLength);
	this->it = ans.begin();
    }
    
    string next() {
	return *this->it++;
    }
    
    bool hasNext() {
	return (this->it + 1 == this->ans.end()) ? false : true;
    }

private:
    vector<string> ans;
    vector<string>::iterator it;

    // Static Combination
    void helper(vector<string> &ret, string s, int len, int index, string &curr) {
	if (curr.size() == len) {
	    // Termination Condition
	    ret.push_back(curr);
	    return;
	}
	if (index > s.size() - 1) return;
	curr.push_back(s[index]);
	helper(ret, s, len, index+1, curr); // append
	curr.pop_back();;
	helper(ret, s, len, index+1, curr); // do not append
    }

    vector<string> staticComb(string s, int len) {
	vector<string> ret; // ans
	string curr = "";
	// dfs + backtracking
	int index = 0;

	helper(ret, s, len, index, curr);

	return ret;
    }
};


// Static Combination
void helper(vector<string> &ret, string s, int len, int index, string &curr) {
    if (curr.size() == len) {
	// Termination Condition
	ret.push_back(curr);
	return;
    }
    if (index > s.size() - 1) return;
    curr.push_back(s[index]);
    helper(ret, s, len, index+1, curr); // append
    curr.pop_back();
    helper(ret, s, len, index+1, curr); // do not append
}

vector<string> staticComb(string s, int len) {
    vector<string> ret; // ans
    string curr = "";
    // dfs + backtracking
    int index = 0;

    helper(ret, s, len, index, curr);

    return ret;
}


int main() {
    for (string s : staticComb("abc", 2)) {
	cout << s << endl;
    }

}

