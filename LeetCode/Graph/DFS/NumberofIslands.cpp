/*
 * LeetCode 200 Number of Islands
 * Medium
 * Shuo Feng
 * 2021.8.7
 */


/*
 * For the point that value = '1' ,make it to '0' and then check the point around it
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int num_islands = 0;
    int numIslands(vector<vector<char>>& grid) {
        for (int n = 0; n < grid.size(); ++n) {
            for (int m = 0; m < grid[0].size(); ++m) {
                if (grid[n][m] == '1') {
                    dfs(grid, n, m);
                    num_islands += 1;
                }
            }
        }
        return num_islands;
    }
  
    void dfs(vector<vector<char>>& grid, int n, int m) {
        grid[n][m] = '0';
        if (n - 1 >= 0              && grid[n - 1][m] == '1') dfs(grid, n - 1, m); //Four directions
        if (n + 1 < grid.size()     && grid[n + 1][m] == '1') dfs(grid, n + 1, m);
        if (m - 1 >= 0              && grid[n][m - 1] == '1') dfs(grid, n, m - 1);
        if (m + 1 < grid[0].size()  && grid[n][m + 1] == '1') dfs(grid, n, m + 1);

        else return;
    }
};
