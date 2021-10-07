/*
 * LeetCode 79 Word Search
 * Medium
 * Shuo Feng 
 * 2021.10.7
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Dfs + backtracking
 */

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int place, int row, int col, vector<vector<bool>>& visited) {
        int row_size = board.size();
        int col_size = board[0].size();

        if (row < 0 || row >= row_size || col < 0 || col >= col_size)
            return false;

        if (visited[row][col])
            return false;

        if (board[row][col] == word[place]) {
            if (place == word.size() - 1)
                return true;

            visited[row][col] = 1;

            bool case_1 = dfs(board, word, place + 1, row + 1, col, visited);
            bool case_2 = dfs(board, word, place + 1, row - 1, col, visited);
            bool case_3 = dfs(board, word, place + 1, row, col + 1, visited);
            bool case_4 = dfs(board, word, place + 1, row, col - 1, visited);

            visited[row][col] = 0;
            return case_1 || case_2 || case_3 || case_4;
        }
        else {
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, 0));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0])
                    if (dfs(board, word, 0, i, j, visited))
                        return true;
            }
        }
        return false;
    }
};
