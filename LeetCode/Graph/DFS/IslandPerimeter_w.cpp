/* 
 * LeetCode 463 Island Perimeter
 * Easy
 * Jiawei Wang
 * 2021.10.4
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 Recursion
    int islandPerimeter1(vector<vector<int>>& grid) {
	const int m = grid.size();
	const int n = grid[0].size();

	for (int i = 0; i < m; ++i) {
	    for (int j = 0; j < n; ++j) {
		if (grid[i][j] == 1) {
		    return dfs(grid, i, j);
		}
	    } 
	}
    }

    int islandPerimeter2(vector<vector<int>>& grid) {
	const int m = grid.size();
	const int n = grid[0].size();

	int area = 0; // total number of cell islands
	int conn = 0;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		if (grid[i][j] == 1) {
		    // if we found a island first assume it is a hole small island 
		    ++area;
		    if (i > 0 && grid[i-1][j])  {
			// if it has a left neighbor
			// 2 sides (left's right and its left)
			++conn;
		    }

		    if (j > 0 && grid[i][j-1])  {
			// if it has a top neighbor
			// 2 sides (top's bottom and its top)
			++conn;
		    }
		}
	    }
	    return area*4 - conn*2; // understand this
	}

    }

private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
	    // Termination Condition
	    return 1;
	}

	if (grid[row][col] == 0) return 1;

	// it is a reached land, just skip
	if (grid[row][col] == 2) return 2;

	grid[row][col] = 2;


	return dfs(grid, row + 1, col)
	    +  dfs(grid, row - 1, col)
	    +  dfs(grid, row, col + 1)
	    +  dfs(grid, row, col - 1);
    }
}

