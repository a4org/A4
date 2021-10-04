/*
 * LeetCode 1886 Determine Whether Matrix Can Be Obtained By Rotation
 * Easy
 * Jiawei Wang
 * 2021 10.4
 */

#include <vector>

using namespace::std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
	for (int i = 0; i < 4; i++) {
	    rotate(mat);
	    if (mat == target) return true;
	}
	return false;
    }

private: 
    // From LeetCode 48 Rotate Image:
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



