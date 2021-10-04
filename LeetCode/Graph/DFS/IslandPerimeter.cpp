/*
 * LeetCode 463 Island Perimeter
 * Easy
 * Shuo Feng
 * 2021.10.4
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Dfs
 *   There is only one island, when reach land, search the place on it`s up, down, left and right, sign the land with '2' 
 *  if the place next to it is water, perimeter add one, 
 */

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        // Coastline on boundary.
        if (   0 > row || row >= grid.size()
            || 0 > col || col >= grid[0].size()) return 1;

        if (grid[row][col] == 0) return 1;

        // Reach land -> skip.
        if (grid[row][col] == 2) return 0;

        // Sign the land.
        grid[row][col] = 2;

        // Four directions.
        return dfs(grid, row + 1, col)
             + dfs(grid, row - 1, col)
             + dfs(grid, row, col + 1)
             + dfs(grid, row, col - 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int Row = grid.size();
        int Col = grid[0].size();

        for (int i = 0; i < Row; ++i) {
            for (int j = 0; j < Col; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};
