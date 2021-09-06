/*
 * LeetCode 118 Pascal`s Triangle
 * Easy
 * Shuo Feng
 * 2021.8.6
 * Last edited at 2021.9.6
 */

/*
 *i=0           1                         For each point in row 'i' (i > 1 ), number in place 'j' is equal to the sum of row'i- 1' place'j' and place 'j- 1'
 *  1         1   1                       (besides begin and end)      
 *  2       1   2   1
 *  3     1   3   3   1
 *             ↘↙
 *  4   1   4   6   4   1 （place）
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // Storage each line.
        vector<vector<int>> triangle;
        
        //triangle[0] = {{1}};
        //triangle[1] = {{1},{1}};
        for(int i = 0; i< numRows; ++i){ 
            
            // In a line both the head and the tail are " 1 ", do not have to change(when j = i and j != 0).
            vector<int> rows(i+1, 1);
            for(int j = 1; j< i && i> 1; ++j){ 
                rows[j] = triangle[i-1][j-1] + triangle[i-1][j];     
            }
            triangle.push_back(rows);
        }
    return triangle;    
    }
};
