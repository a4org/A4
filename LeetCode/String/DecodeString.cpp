/*
 * LeetCode 394 Decode String
 * Medium
 * Jiawei Wang
 * 2021.12.19
 */

#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    string decodeString(string s) {
	// Stack + String + Iteratiion	
	vector<string> sstack; // string stack
	// [a, cc]
	vector<string> nstack;    // number stack
	// [3, 2]
	// always reduce the stack empty while you want to get the output
	int index = 0; // current index
	string ret;

	sstack.push_back("");
	nstack.push_back("");

	helper(sstack, nstack, s, index);

	return sstack.back();
    }

private:
    void helper(vector<string>& sstack, vector<string>& nstack,
	    string s, int index) {
	// iteartion function
	if (index == s.size()) {
	    // termination condition
	    return;
	}

	char cs = s[index]; // current char

	if (cs == '[') {
	    // split 
	    sstack.push_back("");
	    nstack.push_back("");
	} else if (cs == ']') {
	    // merge
	    string sback = sstack.back();
	    if (nstack.back() == "")
		nstack.pop_back();
	    int nback = stoi(nstack.back());
	    sstack.pop_back();
	    nstack.pop_back();

	    // combine it and its back
	    for (int i = 0; i < nback; i++) {
		sstack.back().append(sback);
	    }
	    nstack.push_back("");
	} else {
	    if (cs >= '0' && cs <= '9') {
		nstack.back().push_back(cs);
	    } else {
		// normal char
		sstack.back().push_back(cs);
	    }
	}
	helper(sstack, nstack, s, index+1);
    }
};

