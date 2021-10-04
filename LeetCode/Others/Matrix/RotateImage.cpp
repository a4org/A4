/*
 * LeetCode 48 Rotate Image
 * Medium
 * Jiawei Wang
 * 2021 10.4
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 By Intuition
    //
    // 1   2   3   4
    // 5   6   7   8
    // 9   10  11  12
    // 13  14  15  16
    // 
    //     6   7
    //     10  11
    //
    void rotate(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;

	int top = 0; 
	int left = 0;
	int right = matrix.size() - 1;
	int bottom = matrix.size() - 1;
	int n = matrix.size(); // number of cells in one line

	while (n > 1)  {
	    for (int i = 0; i < n - 1; i++) {
		int tmp = matrix[top][left+i];
		matrix[top][left+i] = matrix[bottom-i][left];
		matrix[bottom-i][left] = matrix[bottom][right-i];
		matrix[bottom][right-i] = matrix[top+i][right];
		matrix[top+i][right] = tmp;
	    }
	    top++;
	    bottom--;
	    left++;
	    right--;
	    n -= 2;
	}
    }
};

