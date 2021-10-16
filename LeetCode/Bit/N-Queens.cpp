/*
 * LeetCode 51 N-Queens
 * Hard
 * Jiawei Wang
 * 2021.10.16
 */

#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
	// Backtracking
	int left = 0; int right = 0; // diagonals (2n-1)
	int col = 0; // each col [0, 9]

	helper(left, right, col, 0, n); 

	return ret;
    }
private:
    vector<vector<string>> ret;
    vector<string> ans;
    string row;
    void helper(int& left, int& right, int& col, int r, int n) {
	// dfs + backtracking
	if (r == n) {
	    // Termination Condition
	    // reach the end (r+1) and still valid
	    ret.push_back(ans);
	    return;
	}
	for (int c = 0; c < n; c++) {
	    if (isValid(left, right, col, r, c, n)) {
		upDate(left, right, col, r, c, n);
		row =  buildQ(c, n);
		ans.push_back(row);
		helper(left, right, col, r+1, n);
		ans.pop_back();
		popDate(left, right, col, r, c, n);
	    }
	}
    }

    bool isValid(int left, int right, int col, int r, int c, int n) {
	return ! ((left & (1 << (r+c))) || (right & (1 << (n-1-r+c))) || (col & (1 << c)));
    }

    void upDate(int& left, int& right, int& col, int r, int c, int n) {
	left |= (1 << (r+c));
	right |= (1 << (n-1-r+c));
	col |= (1 << c);
    }

    void popDate(int& left, int& right, int& col, int r, int c, int n) {
	left &= ~(1 << (r+c));
	right &= ~(1 << (n-1-r+c));
	col &= ~(1 << c);
    }

    string buildQ(int c, int n) {
	string ret;
	for (int i = 0; i < n; i++) {
	    if (i == c) ret.push_back('Q');
	    else ret.push_back('.');
	}
	return ret;
    }

};
