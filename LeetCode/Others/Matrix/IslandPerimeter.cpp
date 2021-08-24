/*
 * LeetCode 463 Island Perimeter 
 * Easy
 * Jiawei Wang
 * 2021 8.24
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
	// Only island cells can affect the perimeter (no lake)
	const int m = grid.size();
	const int n = grid[0].size();
	int area = 0; // total number of cell islands 
	int conn = 0; // each cell island connected with other cells (neighbors)
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		if (grid[i][j] == 1) {
		    ++area;
		    if (i > 0 && grid[i-1][j]) ++conn; // left and left neighbor's right
		    if (j > 0 && grid[i][j-1]) ++conn; // top and top neighbor's beneath
		}
	    }
	}
	return area*4 - conn*2; // conn*2 because two connected neighbors will be affected
    }
};

