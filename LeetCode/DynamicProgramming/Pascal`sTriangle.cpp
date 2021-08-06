/*
 * LeetCode 118 Pascal`s Triangle
 * Easy
 * Shuo Feng
 * 2021.8.6
 */

/*
 *i=0          0                         For each point in row 'i' (i > 1 ), number in place 'j' is equal to the sum of row'i- 1' place'j' and place 'j- 1'
 *  1        0   1                       (besides begin and end)      
 *  2      0   1   2
 *  3    0   1   2   3
 *  4  0   1   2   3   4 （place）
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        //triangle[0] = {{1}};
        //triangle[1] = {{1},{1}};
        for(int i = 0; i< numRows; ++i){ 
            vector<int> rows(i+1, 1);
            for(int j = 1; j< i && i> 1; ++j){ 
                rows[j] = triangle[i-1][j-1] + triangle[i-1][j];     
            }
            triangle.push_back(rows);
        }
    return triangle;    
    }
};
