/* 
 * LeetCode 17 Letter Combinations of a Phone Number
 * Medium
 * Jiawei Wang
 * 2021.9.25
 */

#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    // #1 DFS (BackTracking)
    vector<string> letterCombinations1(string digits) {
	if (digits.empty()) return {};

	vector<string> keyboard(10);
	keyboard[0] = "";
	keyboard[1] = "";
	keyboard[2] = "abc";
	keyboard[3] = "def";
	keyboard[4] = "ghi";
	keyboard[5] = "jkl";
	keyboard[6] = "mno";
	keyboard[7] = "pqrs";
	keyboard[8] = "tuv";
	keyboard[9] = "wxyz";

	string curr;
	vector<string> ans;
	dfs(digits, keyboard, 0, curr, ans);
	return ans;
    }

    // #2 BFS 
    vector<string> letterCombinations2(string digits) {
	if (digits.empty()) return {};

	vector<string> keyboard(10);
	keyboard[0] = "";
	keyboard[1] = "";
	keyboard[2] = "abc";
	keyboard[3] = "def";
	keyboard[4] = "ghi";
	keyboard[5] = "jkl";
	keyboard[6] = "mno";
	keyboard[7] = "pqrs";
	keyboard[8] = "tuv";
	keyboard[9] = "wxyz";

	vector<string> ans = {""};
	for (char digit : digits) {
	    vector<string> tmp;
	    for (const string& s : ans) 
		for (char c : keyboard[digit - '0']) 
		    tmp.push_back(s + c);

	    ans.swap(tmp);
	}
	return ans;
    }

private:
    void dfs(const string& digits, 
	    const vector<string>& keyboard,
	    int l, string& curr, vector<string>& ans) {

	if (l == digits.length()) {
	    // Termination Condition
	    ans.push_back(curr);
	    return;
	}

	for (const char c : keyboard[digits[l] - '0']) {
	    curr.push_back(c);
	    dfs(digits, keyboard, l + 1, curr, ans);
	    curr.pop_back();
	}
    }
};

