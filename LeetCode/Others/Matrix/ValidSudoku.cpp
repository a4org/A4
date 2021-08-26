/*
 * LeetCode 36 Valid Sudoku
 * Medium
 * Shuo Feng
 * 2021.7.25
 */

/*
 *   Using three arrays to stoarge the situation of each number in their area (horizontal, vertial and block), " 1 " stand existence, 
 *  and " 0 " stand inexistence, when search repeated numbers( reach " 1 " ), this sudoku is invalid.
 *
 * Place in box:
 *   The arrangement of all the box [(3 x 3) x 9] is :
 *                      0    1    2
 *                      3    4    5 ←*
 *                      6    7    8
 *   
 *   To get such a sequence, acroding to the specialty of " / ",  from" j / 3 + (i / 3) * 3 " we can get the place of each box.(line 44)
 *   For example:  j →
 *                   6  7  8
 *             i    ┌──┬──┬──┐  place: 5 
 *             ↓ 3  ├──┼──┼──┤ 
 *               4  ├──┼──┼──┤
 *               5  └──┴──┴──┘
 */ 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>>horizontal(9, vector<char>(9, 0)); // 一  Nine rows and nine numbers
        vector<vector<char>>vertial   (9, vector<char>(9, 0)); // |
        vector<vector<char>>block     (9, vector<char>(9, 0)); // 口

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;

                int value = board[i][j] - '1';  // Change 1 ~ 9 to Range : 0 ~ 8
                int block_place = j / 3 + (i / 3) * 3;

                if (horizontal[i][value] == 0 && vertial[j][value] == 0 && block[block_place][value] == 0) {
                    horizontal[i][value] = 1;
                    vertial[j][value] = 1;
                    block[block_place][value] = 1;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
