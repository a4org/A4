/*
 * LeetCode 201 Bitwise AND of Numbers Range
 * Medium
 * Jiawei Wang
 * 2021.10.10
 */

#include <iostream>

using namespace::std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
	// prefix(|) suffix (0)
	int answer = 0;
	for (int bit = 31; bit >= 0; bit--) {
	    if ((m & (1 << bit)) != (n & ( 1 << bit))) {
		break;
	    }
	    else {
		answer |= (m & (1 << bit)); // just keep the same prefix
	    }
	}
	return answer;
    }
};
