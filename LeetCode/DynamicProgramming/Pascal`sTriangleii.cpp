/*
 * LeetCode 119 Pascal`s Triangle ii.
 * Easy
 * Shuo Feng
 * 2021.8.7
 * Last edited at 2021.9.6
 */


#include<iostream>.
#include<vector>
using namespace std;

/*
 * Solution : Dp.
 *   From top to bottom, record each line, and the " rowIndex " line is the one to return.
 *   On the basic of LeetCode 118 Pascal`s Triangle, we can find the value on each point.
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;

        for (int i = 0; i <= rowIndex; ++i) {
            
            // vector to storage " i + 1 " line.
            vector<int> rows(i + 1, 1);
            for (int j = 1; j < i && i> 1; ++j) {
                
                rows[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(rows);
        }
        return triangle[rowIndex];
    }
};
