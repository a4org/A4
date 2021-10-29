/*
 * LeetCode 994 Rotting Oranges
 * Medium
 * Shuo Feng
 * 2021.10.30
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 * Solution: Bfs
 */

class Solution {
private:
    // Four direction.
    vector<int> dir_x{ 1, 0, -1,  0 };
    vector<int> dir_y{ 0, 1,  0, -1 };

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // All contagious oranges in the same time.
        queue<pair<int, int>> q;

        // Number of fresh oranges.
        int fresh = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1)
                    fresh += 1;

                // Rotting orange -> enqueue.
                else if (grid[i][j] == 2)
                    q.push({ i, j });
            }
        }

        int min = 0;  // Minute.
        while (!q.empty() && fresh > 0) {
            // Start new round of infection.
            min += 1;

            // There`re 'nums' contagious oranges in this round.
            int nums = q.size();
            for (int i = 0; i < nums; ++i) {

                pair<int, int> orange = q.front();  // A rotting orange.
                q.pop();
                int R = orange.first; // row
                int C = orange.second;// Col 

                // Search four direction around rotting orange.
                for (int d = 0; d < 4; ++d) {
                    int next_row = R + dir_x[d];
                    int next_col = C + dir_y[d];

                    // Find fresh orange.
                    if (next_row >= 0 && next_row < row && next_col >= 0 && next_col < col && grid[next_row][next_col] == 1) {
                        // Fresh orange rot.
                        grid[next_row][next_col] = 2;
                        fresh -= 1;
                        // New rotting orange enqueue.
                        q.push({ next_row, next_col });
                    }
                }
            }
        }

        // Whether still have fresh oranges.
        if (fresh > 0)
            return -1;
        else
            return min;
    }
};
