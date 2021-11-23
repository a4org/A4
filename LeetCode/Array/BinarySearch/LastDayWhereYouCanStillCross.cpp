/* 
 * LeetCode 1970 Last Day Where You Can Still Cross
 * Hard
 * Jiawei Wang
 * 2021.11.23
 */

#include <vector>
#include <queue>

using namespace::std;

class Solution {
public:
    // #1 Binary Search
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
	int left = 1, right = cells.size()-1, ans = 0;
	while (left < right) {
	    int mid = left + (right-left)/2; // left
	    if (canWalk(cells, row, col, mid)) {
		ans = mid;
		left = mid + 1;
	    } else {
		right = mid; // Key Binary Seach
	    }
	}
	return ans;
    }

    // #2 Union Find
    // Please check the same name inside LeetCode/Graph/UnionFind
private:
    int DIR[5] = {0, 1, 0, -1, 0};
    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt) {
	vector<vector<bool>> grid(row, vector<bool>(col, 0)); // the grid in the `datAt` date
	for (int i = 0; i < dayAt; i++) {
	    grid[cells[i][0]-1][cells[i][1]-1] = 1;
	}
	queue<pair<int, int>> bfs;
	for (int c = 0; c < col; c++) {
	    if (grid[0][c] == 0) {
		bfs.push({0, c});
		grid[0][c] = 1;
	    }
	}

	while (!bfs.empty()) {
	    int r = bfs.front().first, c = bfs.front().second;
	    bfs.pop();
	    if (r == row-1) return true;

	    for (int i = 0; i < 4; i++) {
		int nr = r + DIR[i], nc = c + DIR[i+1];
		if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue;
		grid[nr][nc] = 1; // Mark as Visited
		bfs.push({nr, nc});
	    }
	}
	return false;
    }
};

