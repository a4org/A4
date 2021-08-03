/*
 * LeetCode 62 Unique Paths
 * Medium
 * Shuo Feng
 * 2021.8.3
 */                                               
                                             
/*   For each points ,there are two path lead to it (" move either down or right ")(expect the points on left border，top border and origin). 
 *   
 *   We can use ' Path_num[i][j] ' to store the number of path which lead to point (i, j) ，so we can konw that:
 *                 Path_Num[i][j] = Path_Num[i-1][j] + Path_Num[i][j-1];
 *
 *   In a straight line ,only one path lead to each points on it. 
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> Paths_Num (m, vector<int>(n));
        for(int i = 0; i< m; ++i) Paths_Num[i][0] = 1;
        for(int j = 0; j< n; ++j) Paths_Num[0][j] = 1;
        for(int i = 1; i< m; ++i)
            for(int j = 1; j< n; ++j)
                Paths_Num[i][j] = Paths_Num[i-1][j] + Paths_Num[i][j-1];

    return Paths_Num[m-1][n-1];    
    }
};



/*
 *   The other way I`ve used, it`s about traversal .
 *   When the grid is large, it`s very inefficient, so it is unreliable.
 */

class Solution {
public:
    int Paths_Num;
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        traverse(m, n);
        return Paths_Num;
    }
    void traverse(int m, int n) {
        if (m > 1 && n > 1) {
            traverse(m - 1, n);
            traverse(m, n - 1);
        }
        if (m == 1 || n == 1) Paths_Num += 1;
    }
};
