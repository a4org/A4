/* 
 * LeetCode 79 Word Seach
 * Medium
 * Jiawei Wang
 * 2021.10.7
 */


#include <vector>
#include <string>

using namespace::std;



class Solution {
public:
    // DFS + Backtracking
    // Four dircetions
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> bt(m, vector<int>(n)); // backtracking
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, 0, word, i, j, bt)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, string word, int x, int y, vector<vector<int>>& bt) {
        // termination condition
        bool t = false, b = false, l = false, r = false;
        if (i == word.size()-1 && board[x][y] == word[i] && !bt[x][y]) {
            return true;
        }
        
        if (board[x][y] == word[i] && !bt[x][y]) {
            bt[x][y] = 1;
            if (x > 0) l = dfs(board, i+1, word, x-1, y, bt);
            if (x < board.size()-1) r = dfs(board, i+1, word, x+1, y, bt);
            if (y > 0) t = dfs(board, i+1, word, x, y-1, bt);
            if (y < board[0].size()-1) b = dfs(board, i+1, word, x, y+1, bt);
            bt[x][y] = 0;
            return (t || b || l || r);
        }
      
        
        return false;
    }
};
