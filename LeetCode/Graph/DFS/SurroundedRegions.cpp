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
