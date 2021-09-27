/*
 * LeetCode 48 Rotate Image
 * Medium-
 * Shuo Feng
 * 2021.9.27
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution 1:
 *                                                            ╭ Row     = Col.
 *   To rotate image, for each point we can get such a rule: ─┤ 
 *                                                            ╰ Col     = Size - Row.
 *                                                              (before)  (after)
 *                                          
 *                 matrix[Size - Col][Row] -> matrix[Row][Col]   ↗  ↘    matrix[Row][Col] -> matrix[Col][Size - Row]
 *                                                            ↗        ↘
 *                                                            ↖        ↙
 *   matrix[Size - Row][Size - Col] -> matrix[Size - Col][Row]   ↖  ↙    matrix[Col][Size - Row] -> matrix[Size - Row][Size - Col]
 *
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int Row = 0; Row < size / 2; ++Row) {
            for (int Col = 0; Col < (size + 1) / 2; ++Col) {
                
                int Size = size - 1;
                int replace = matrix[Row][Col];
                matrix[Row][Col] = matrix[Size - Col][Row];
                matrix[Size - Col][Row] = matrix[Size - Row][Size - Col];
                matrix[Size - Row][Size - Col] = matrix[Col][Size - Row];
                matrix[Col][Size - Row] = replace;
            }
        }
    }
};

/*
 * Solution 2: 
 *   Change twice, Symmetry axis: (2)╲   (1)│
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <= i; ++j) {
                int replace = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = replace;
            }
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size / 2; ++j) {
                int replace = matrix[i][j];
                matrix[i][j] = matrix[i][size - j - 1];
                matrix[i][size - j - 1] = replace;
            }
        }
    }
};
