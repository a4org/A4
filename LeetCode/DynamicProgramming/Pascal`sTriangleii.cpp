/*
 * LeetCode 119 Pascal`s Triangle ii.
 * Easy
 * Shuo Feng
 * 2021.8.7
 */


#include<iostream>.
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;

        for (int i = 0; i <= rowIndex; ++i) {
            vector<int> rows(i + 1, 1);
            for (int j = 1; j < i && i> 1; ++j) {
                rows[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(rows);
        }
        return triangle[rowIndex];
    }
};
