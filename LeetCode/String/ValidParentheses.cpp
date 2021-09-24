/*
 * LeetCode 20 Valid Parentheses
 * Easy
 * Jiawei Wang
 * 2021.9.24
 */

#include <string>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    bool isValid(string s) {
	int n = s.size();
	if (n <= 1) return false;

	unordered_map<char, char> Parentheses = {{'{', '}'}, {'[', ']'}, {'(', ')'}}; // map the Parentheses
	stack<char> leftP;
	char prev = s[0];
	leftP.push(prev);

	for (int i = 1; i < n; i++) {
	    if (Parentheses[prev] == s[i]) {
		leftP.pop();
		if (!leftP.empty()) prev = leftP.top();
		else prev = ' '; // set the null prev since there is no left brackets left now
	    } else {
		leftP.push(s[i]); // left bracket
		prev = s[i];
	    }
	}
	if (leftP.empty()) return true;
	return false;
    }
};
