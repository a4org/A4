/*
 * LeetCode 980 Path Sum iii
 * Hard
 * Shuo Feng
 * 2021.11.2
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution 1: Dfs with Tracking Back.
 */

class Solution {
private:
    // Gather all paths.
    vector<vector<int>> res;
    // Four directions.
    vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
  
    // 'passed' : empty sqares we have passed. 'empty': quantity of empty squares.
    void dfs(vector<vector<int>>& grid, vector<int>& path, int x, int y, int empty, int passed) {
        int row = grid.size();
        int col = grid[0].size();

        // Meet obstacle (include passed cells).
        if (grid[x][y] == -1)
            return;

        // Meet end square.
        if (grid[x][y] == 2) {
            // Condition: pass all empty squares and we have not pass this path.
            if (passed == empty && find(res.begin(), res.end(), path) == res.end()) {
                res.push_back(path);
                return;
            }
            else
                return;
        }

        path.push_back((col + 1) * x + y + 1);
        grid[x][y] = -1;
        
        // Search in four(or three) directions.
        for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                dfs(grid, path, nx, ny, empty, passed + 1);
            }
        }
        // Tracking back
        path.pop_back();
        grid[x][y] = 0;
        return;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // Count begin with 1 
        // Explain: each time we move, 'passed' add one(line 49), include ending square, so in the end, 'passed' = quantity of empty squares + 1.
        int empty = 1;  // Quanlity of empty squares.
        pair<int, int> begin;  // Beginning square.
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1)
                    begin = { i, j };

                else if (grid[i][j] == 0)
                    empty += 1;
            }
        }
        vector<int> path = {};
        dfs(grid, path, begin.first, begin.second, empty, 0);

        // Return number of non-repeating path.
        return res.size();
    }
};


/*
 * Solution 1.5: Improve on the basis of Solution 1.
 *   On a squares, since we go in each direction only once, we do not consider repeated path, just count all path.
 */

class Solution {
public:
    int res = 0;
    int empty = 1;
    void dfs(vector<vector<int>>& grid, int x, int y, int passed) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;

        if (grid[x][y] == 2) {
            if (empty == passed) res++;
            return;
        }

        grid[x][y] = -1;

        dfs(grid, x + 1, y, passed + 1);
        dfs(grid, x - 1, y, passed + 1);
        dfs(grid, x, y + 1, passed + 1);
        dfs(grid, x, y - 1, passed + 1);

        grid[x][y] = 0;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                else if (grid[i][j] == 0) empty++;
            }
        }

        dfs(grid, x, y, 0);
        return res;
    }
};
