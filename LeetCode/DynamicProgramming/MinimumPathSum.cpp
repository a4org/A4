/*
 * LeetCode 64 Minimum Path Sum
 * Medium
 * Shuo Feng
 * 2021.8.5
 */

/*
 * To save memory，cumulate data in 'grid', each point refer to the minimum path sum about itself. 
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int path;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();     // row
        int n = grid[0].size();  // list

        if (m == 1 && n == 1) return grid[0][0];
        for (int i = 1; i < m; ++i) grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; ++i) grid[0][i] += grid[0][i - 1];  //original condition

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
