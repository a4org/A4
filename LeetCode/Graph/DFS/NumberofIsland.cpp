/*
 * LeetCode 200 Number of Islands
 * Medium
 * Jiawei Wang
 * 2021 8.24
 */

/* Revision 
 * $1 2021.10.4 Jiawei Wang
 */

#include <vector>

using namespace::std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x) {
                ans += grid[y][x] - '0'; // ans += 1
                dfs(grid, x, y, m, n);
            }
        return ans;                
    }   
private:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
	// search current position cell island
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
            return;
        grid[y][x] = '0'; // a very brilliant way to divide each islands -- set the counted islands to '0'
        dfs(grid, x + 1, y, m, n);
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x, y + 1, m, n);
        dfs(grid, x, y - 1, m, n);
    }
};

