/*
 * LeetCode 695 Max Area of Island
 * Medium
 * Shuo Feng
 * 2021.8.10
 * Last edited at 2021.9.9
 */
 
/*
 * Solution: Dfs.
 *   Check each point, when reach " 1 ", dfs four direction, mark the point as  0  when it`s a part of island.
 *   
 */ 

 #include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int max_size = 0;
    //int size = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for (int n = 0; n < grid.size(); ++n) {
            for (int m = 0; m < grid[0].size(); ++m) {
                if (grid[n][m] == 1) {
                    int size = dfs(grid, n, m);
                    if (max_size < size) {
                        max_size = size;
                    }
                }
            }
        }
        return max_size;
    }

    int dfs(vector<vector<int>>& grid, int n, int m) {
        int size = 1;
        if (  n< 0 || n>= grid.size() || m< 0 || m>= grid[0].size() || grid[n][m] == 0)
            return 0;
     
        // Update the value of max size.
        grid[n][m] = 0;
        size += dfs(grid, n - 1, m);
        size += dfs(grid, n + 1, m);
        size += dfs(grid, n, m - 1);
        size += dfs(grid, n, m + 1);
        return size;
    }
};
