/*
 * LeetCode 980 Unique Paths iii
 * Hard
 * Jiawei Wang
 * 2021.11.2
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // DFS
    int uniquePathsIII(vector<vector<int>>& grid) {
	// Walk over every non-obstacle square exactly once.
	// if remain is 0 then return -> do dfs
	int m = grid.size(), n = grid[0].size();
	int nobstacle = 1, ret = 0;

	vector<int> SP;
	
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) {
		if (grid[i][j] == 0) nobstacle++;
		if (grid[i][j] == 1) SP = {i, j};
	    }
	}
	helper(grid, nobstacle, m, n, SP[0], SP[1], ret);
	return ret;
    }


	
private:
    void helper(vector<vector<int>>& Grid, int& nobstacle, int m, int n, int x, int y, int& ret) {

	if (x < 0 || x > m-1 || y < 0 || y > n-1 || Grid[x][y] == -1) {
	    // Termination Condition #1
	    return;
	}

	if (Grid[x][y] == 2) {
	    // Termination Condition #2
	    // Got one valid answer
	    if (nobstacle == 0)
		ret++;
	    return;
	}


	Grid[x][y] = -1;
	nobstacle--;
	helper(Grid, nobstacle, m, n, x+1, y, ret);
	helper(Grid, nobstacle, m, n, x-1, y, ret);
	helper(Grid, nobstacle, m, n, x, y+1, ret);
	helper(Grid, nobstacle, m, n, x, y-1, ret);
	Grid[x][y] = 0;
	nobstacle++;

	return;
    }
    
};
