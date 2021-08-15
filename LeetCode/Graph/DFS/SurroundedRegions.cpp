/*
 * LeetCode 130 Surrounded Regions
 * Medium
 * Shuo Feng
 * 2021.8.12
 */


 /*
  * Solution 1 : dfs
  *  Find the  ' O ' in boundary and sign the points connected with it ,
  *  change the signed points to ' O ' and change ' O ' to ' X '. 
  * 
  */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //  Check left and right boundary
        for(int i = 0; i< m; ++i){
            dfs(board, i, 0);
            dfs(board, i, n- 1);
        }

        //  Check upper and lower boundary
        for(int i = 0; i< n; ++i){
            dfs(board, 0, i);
            dfs(board, m- 1, i);
        }

        for(int i = 0; i< m; ++i){
            for(int j = 0; j< n; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '5') board[i][j] = 'O';
            }
        }
    }
    void dfs (vector<vector<char>>& board, int i, int j){
        if (  i< 0 || i>= board.size() 
           || j< 0 || j>= board[0].size() || board[i][j] != 'O') return ;
        board[i][j] = '5';    
        dfs(board, i- 1, j);
        dfs(board, i+ 1, j);
        dfs(board, i, j- 1);
        dfs(board, i, j+ 1);
        return;
    }
};


/*
 * Solution 2: Bfs
 * 2021.8.15
 */

 /* 
  * In line 70 71 , use " r[i] " and " c[i] " to show four directions,
  *
  */
 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    const int r[4] = {1, -1, 0, 0}; // Four directions
    const int c[4] = {0, 0, 1, -1};
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        queue<pair<int, int>> q;
        
      // Search " O " in four borders:
        // Left and right
        for(int i = 0; i< row; ++i){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'T';
            }
            if(board[i][col- 1] == 'O'){
                q.push({i, col- 1});
                board[i][col- 1] = 'T';
            }
        }
        
        // Up and down
        for(int i = 0; i< col; ++i){
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = 'T';
            }
            if(board[row- 1][i] == 'O'){
                q.push({row- 1, i});
                board[row- 1][i] = 'T';
            }
        }
        
        // Bfs the " O " point, and replace it as " T " 
        while(!q.empty()){
            auto point = q.front();
            q.pop();
            int Row = point.first;
            int Col = point.second;
            
            for (int i = 0; i < 4; i++) {
                int R = Row + r[i];
                int C = Col + c[i];
                if (R< 0 || R>= row || C< 0 || C>= col || board[R][C] != 'O') continue;
                board[R][C] = 'T';
                q.emplace(R, C);
            }  
        }
        
        //
        for(int i = 0; i< row; ++i){
            for(int j = 0; j< col; ++j){
                if     (board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
