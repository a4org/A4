/*
 * LeetCode 1446 Consecutive Characters
 * Easy
 * Jiawei Wang
 * 2021.12.13
 */

#include <string>

using namespace::std;

class Solution {
public:
    int maxPower(string s) {
	int ret = 1;
	int curr = 1;
	char cc = ' ';
	int ns = s.size();
	cc = s[0];

	char c;
	for (int i = 1; i < ns; i++) {
	    c = s[i];
	    if (cc == c) {
		curr++;
	    } else {
		ret = max(ret, curr);
		curr = 1;
	    }
	    cc = c;
	}
	ret = max(ret, curr);
	return ret;
    }
};
