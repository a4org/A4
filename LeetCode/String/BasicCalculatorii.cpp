/*
 * LeetCode 227 Basic Calculator ii
 * Medium
 * Jiawei Wang
 * 2021.12.25
 */

#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int calculate(string s) {
	// single operator (e.g. +3 *8 /2)
	string S = "+";
	for (auto ch : s) {
	    if (ch == ' ') continue;
	    S.push_back(ch);
	}

	s = S;

	vector<int> nums; // nums stack

	for (int i = 0; i < s.size(); i++) {
	    if (s[i] == '+' || s[i] == '-') {
		// Just push back into vector 

		// get the number
		int j = i+1;
		while(j < s.size() && isdigit(s[j])) j++;
		int num = stoi(s.substr(i+1, j-i-1));

		if (s[i] == '+') nums.push_back(num);
		else if (s[i] == '-') nums.push_back(-num);
		i = j-1;
	    }

	    else if (s[i] == '*' || s[i] == '/') {
		// just calculate with the back of the stack

		// get the number
		int j = i + 1;
		while (j < s.size() && isdigit(s[j])) j++;
		int num = stoi(s.substr(i+1, j-i-1));
		if (s[i] == '*') nums.back() *= num;
		else if (s[i] == '/') nums.back() /= num;
	    }
	}

	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
	    ret += nums[i];
	}
	return ret;
    }
};
