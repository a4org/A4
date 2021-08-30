/*
 * LeetCode 85 Maximal Rectangle
 * Hard
 * Jiawei Wang
 * 2021 8.30
 */

#include <vector>

using namespace::std;

/* Example:
 * Matrix
 * 1  0  1  0  0
 * 1  0  1  1  1 
 * 1  1  1  1  1
 * 1  0  0  1  0
 *
 * dp
 * 1  0  1  0  0
 * 2  0  2  1  1
 * 3  1  3  2  2  
 * 4  0  0  3  0
 */


class Solution {
public:
  // Dynamic Programming
  int maximalRectangle(vector<vector<char> > &matrix) {
    int r = matrix.size();
    if (r == 0) return 0;
    int c = matrix[0].size();
  
    // dp[i][j] := max len of all 1s ends with col j at row i.
    vector<vector<int>> dp(r, vector<int>(c));
 

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;
 
    int ans = 0;


    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        int len = INT_MAX;
        for (int k = i; k < r; k++) {
          len = min(len, dp[k][j]); // len := maximal length with col j at row k
          if (len == 0) break; // this statement is very important:
	  // if len == 0, means the value of current matrix[k][j] is 0, not one
	  // use this prooerty, we can find the longest adjacency x length and multiple with current shortest adjacency y length 
	  // and update ans each time we will get the answer
          ans = max(len * (k - i + 1), ans);
        }
    }

    return ans;
  }
};
