/*
 * LeetCode 695 Max Area of Island
 * Medium
 * Jiawei Wang
 * 2021 8.24
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // Just like LC 200 Number of Islands
    int maxAreaOfIsland(vector<vector<int>>& grid) {
	if (grid.empty()) return 0;
	int m = grid.size();
	int n = grid[0].size();
	int maxa = 0;

	for (int i = 0; i < m; ++i) { 
	    for (int j = 0; j < n; ++j) {
		if (grid[i][j] == 0) continue;
		int temp = 0;
		// Start from this point (search)
		dfs(grid, j, i, m, n, temp); 
		maxa = max(temp, maxa);
	    }
	}
	return maxa;
    }

private:
    void dfs(vector<vector<int>>& grid, int x, int y, int m, int n, int& temp) {
	// search current position cell island
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == 0)
            return;
	temp += 1; // cell island
        grid[y][x] = 0; // a very brilliant way to divide each islands -- set the counted islands to '0'
        dfs(grid, x + 1, y, m, n, temp);
        dfs(grid, x - 1, y, m, n, temp);
        dfs(grid, x, y + 1, m, n, temp);
        dfs(grid, x, y - 1, m, n, temp);
    }
};

