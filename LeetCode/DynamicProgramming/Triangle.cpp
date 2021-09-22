/*
 * LeetCode 120 Triangle
 * Medium
 * Shuo Feng
 * 2021.8.23
 * Last edited at 2021.9.22
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution 1: Dp (from top to bottom)
 *
 *   Creat a double dimensional array 'sum', for each place storage the shortest path to it.
 *   There are two paths lead to place" [i][j] "(besides left and right boundary, [0][0]), and the path sum is " sum[i - 1][j - 1] + triangle[i][j] "
 *  or " sum[i - 1][j] + triangle[i][j] ", choose the shortest one.
 */  

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> sum(size, vector<int>(size)); // Used to storage the shortest way.
        int size = triangle.size();
        sum[0][0] = triangle[0][0];

        for (int i = 1; i < size; ++i) {
            sum[i][0] = sum[i - 1][0] + triangle[i][0]; // The left boundary.
            int size_2 = triangle[i].size();
 
            for (int j = 1; j < size_2; ++j) {
                sum[i][j] = min(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j]; // Places between two boundaries
            }
            sum[i][i] = sum[i - 1][i - 1] + triangle[i][i]; // The right boundary
        }

        // Select the minimum one in last line.
        int Min = INT_MAX;
        for (int i = 0; i < size; ++i) {
            if (sum[size - 1][i] < Min)
                Min = sum[size - 1][i];
        }
        return Min;
    }
};


/*
 * Solution 2: Dp (from bottom to top)
 * The better way
 * 
 *   Begin with the line before the last line, for place 'j' in this line there are two optional paths to go, choose the minimum one
 *  and add it to place 'j'. In next cycle, move up and repeat, when reach the last place( [0][0] ), it`s number is the the minimum path.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        for (int i = size - 2; i >= 0; --i) {
            int size_2 = triangle[i].size();

            for (int j = 0; j < size_2; ++j) {
                // Choose the minimum one beetween the next two paths.
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
