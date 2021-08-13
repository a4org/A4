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


/* 
 * Solution 2 bfs
 * 2021.8.13 
 */

 /*
  *  About     " auto i = near.front(); "    
  *            " near.pop(); "
  *             
  *  in line 79, 80 :
  *
  *   Use " i " to get the point we check ,
  *   to make sure the point we get is next point, delete the before one ,before add the next point to queue.
  */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int num_islands = 0;
    int numIslands(vector<vector<char>>& grid) {
        // Storage the point and it`s place
        queue<pair<int, int>> near;

        for (int n = 0; n < grid.size(); ++n) {
            for (int m = 0; m < grid[0].size(); ++m){
                if(grid[n][m] == '1'){
                    near.push({n, m});
                    num_islands += 1;                    

                    while(!near.empty()){
                        auto i = near.front();
                        near.pop();
                        int nn = i.first;
                        int mm = i.second;
                        
                        if(nn- 1>=  0              && grid[nn- 1][mm] == '1'){
                            grid[nn- 1][mm] = '0';
                            near.push({nn- 1, mm});
                        }
                        if(nn+ 1<  grid.size()     && grid[nn+ 1][mm] == '1'){
                            grid[nn+ 1][mm] = '0';
                            near.push({nn+ 1, mm});
                        }
                        if(mm- 1>= 0               && grid[nn][mm- 1] == '1'){
                            grid[nn][mm- 1] = '0';
                            near.push({nn, mm- 1});
                        }
                        if(mm+ 1<  grid[0].size()  && grid[nn][mm+ 1] == '1'){
                            grid[nn][mm+ 1] = '0';
                            near.push({nn, mm+ 1});
                        }
                    }
                }
            }
        }
    return num_islands;    
    }
};
   
