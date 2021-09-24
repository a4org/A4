/*
 * LeetCode 22 Generate Parentheses
 * Medium
 * Jiawei Wang
 * 2021 9.24
 */

#include <string>
#include <vector>

using namespace::std;

/*                             
 *                     ( 
 *                    / \
 *                  ((   ()
 *                 /  \   \
 *              (((   (()  ()(
 *               |   /   \ /  \
 *               |  ...........
 *             ((()))
 *
 */

class Solution {
public:
    // Backtracking (DP + DFS)
    vector<string> generateParenthesis(int n) {
        vector<string> res;
	// all valid parentheses must have n '(' and n ')'
	helper("", res, n, 0, 0);
        return res;
    }

private:
    void helper(string curr, vector<string> &res, int n, int left, int right) {
	// left, right stand for current '(' and ')' we have
	if (right == n) {
	    res.push_back(curr);
	    return;
	}
	// key: left must larger than right, otherwise there will be a ")("
	if (left < n) {
	    helper(curr+'(', res, n, left+1, right);
	} 
	if (right < left) {
	    helper(curr+')', res, n, left, right+1);
	}
    }
};

