/*
 * LeetCode 200 Number of Islands
 * Medium
 * Jiawei Wang
 * 2021 8.24
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // BFS
    int orangesRotting(vector<vector<int>>& grid) {
        // any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> Curr, Next;
	vector<vector<int>> grids = grid; // copy of grid (for dfs)
	int orange = 0; // check whether there are any fresh orange
        
        // find islands if not then continue rotten
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
		if (grids[i][j] == 2) {
		    // first "any" rotten orange
		    Curr.push_back({i, j});
		} else if (grids[i][j] == 1 && isIsland(i, j, m, n, grids)) {
		    return -1;
		} 

		if (grid[i][j] == 1) orange = 1; 
	    }
        }
        
	// BFS
	int ret = -1; // Ret Time
	while (!Curr.empty()) {
	    ret++;
	    for (auto rott : Curr) {
		// for dircetions
		int x = rott[0], y = rott[1];

		if (x > 0 && grid[x-1][y] == 1) {
		    Next.push_back({x-1, y});
		    grid[x-1][y] = 0;
		}

		if (y > 0 && grid[x][y-1] == 1) {
		    Next.push_back({x, y-1});
		    grid[x][y-1] = 0;
		}

		if (x < m-1 && grid[x+1][y] == 1) {
		    Next.push_back({x+1, y});
		    grid[x+1][y] = 0;
		}

		if (y < n-1 && grid[x][y+1] == 1) {
		    Next.push_back({x, y+1});
		    grid[x][y+1] = 0;
		}
	    }
	    Curr.swap(Next);
	    Next.clear();
	}
	return (orange == 0) ? 0 : ret;
    }

private:
    bool isIsland(int x, int y, int m, int n, vector<vector<int>>& grids) {
	if (x < 0 || y < 0 || x > m-1 || y > n-1 || grids[x][y] == 0) {
	    // Termination Condition (hit the boundary)
	    return true;
	}

	if (grids[x][y] == 2 || grids[x][y] == -1)  {
	    // Termination Condition
	    // there is a Rott-orange in our "island"
	    return false;
	}

	grids[x][y] = 0;
	int bt = isIsland(x+1, y, m, n, grids);
	int tp = isIsland(x-1, y, m, n, grids);
	int ri = isIsland(x, y+1, m, n, grids);
	int le = isIsland(x, y-1, m, n, grids);
	return bt && tp && ri && le;
    }
};

