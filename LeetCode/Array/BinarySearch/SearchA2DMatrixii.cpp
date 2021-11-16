/*
 * LeetCode 240 Kth Search a 2D Matrix ii
 * Medium
 * Jiawei Wang
 * 2021.11.16
 */

#include <vector>

using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();

	// both starting from low-left corner or top-right corner are correct
	int i = m-1;
	int j = 0;

	while (i >= 0 && j < n) {
	    if (matrix[i][j] == target) 
		return true;
	    if (matrix[i][j] < target) {
		// go right
		j++;
	    } else {
		// go up
		i--;
	    }
	}
	return false;
    }
};
