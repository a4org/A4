/*
 * LeetCode 902 Numbers At Most N Givenn Digit Set
 * Hard
 * Jiawei Wang
 * 2021 12.18
 */

#include <string>
#include <cmath>
#include <vector>

using namespace::std;

class Solution {
public:
    // #1 Simple DFS but TLE
    int atMostNGivenDigitSet1(vector<string>& digits, int n) {
	helper1(0, digits, n);
	return count;
    }

private:
    int count = 0;
    void helper1(long curr, vector<string>& digits, int n) {
	if (curr > n) return;
	if (curr > 0 && curr <= n) count++;
	for (string s : digits) {
	    helper1(curr*10 + stoi(s), digits, n);
	}
    }

public:
    // #2 DFS (change the n to string and just split it char by char)
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
	num = to_string(n);
	size = num.size(); // change

	for (int i = 1; i < size; i++) {
	    // if the digit is less than size, then any combination is ok
	    ret += pow(digits.size(), i);
	}

	helper(0, digits);

	return ret;

    }
private:
    int ret = 0;
    string num;
    int size;

    void helper(int pos, vector<string> digits) {
	if (pos == size) {
	    ret += 1;
	    return;
	}

	for (string s : digits) {
	    if ('0' + stoi(s) < num[pos]) {
		// if pos digit number is less than the limit pos
		ret += pow(digits.size(), size-1-pos);
		// just count any permutations after this position
		// and then return
	    } else if ('0' + stoi(s) == num[pos]) {
		helper(pos+1, digits);
	    }
	}

    }
};
