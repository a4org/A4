/*
 * LeetCode 221 Maximal Square
 * Medium
 * Jiawei Wang
 * 2021 6.13
 */

/* Revisions
 * $1 2021.8.30 Jiawei Wang
 */

#include <iostream>
#include <vector>

using namespace::std;

// #1 Brutal + DP
/* Example:
 * Matrix
 * 1  0  1  0  0
 * 1  0  1  1  1
 * 1  1  1  1  1 
 * 1  0  0  1  0 
 *
 * Sum (Sum[i][j] --> point in Matrix[i-1][j-1]) ("*" represents get answer at this point)
 * 1  1  2  2  2
 * 2  2  4  5  6
 * 3  4  7  9* 11* 
 * 4  5  8  11 13
 *
 * We can get that: (DP)
 * Sum[i][j] -> How many "1"s in the rectangle if we use matrix[i-1][j-1] as low-right point
 * Key point to understand this Brute Force way
 *
 * Area (Area[i][j] represents the maximum area of rectangle(if can) if we use matrix[i-1][j-1] as low-right point) 
 * 
 */


// #2 Dynamic Programming
/*
 * dp[i][j] represents the maximum side length of the square with (i, j) in the lower right corner
 *
 * if dp[i][j] == 1:
 * dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
 *
 * Example:
 * Matrix
 * 1  0  1  0  0
 * 1  0  1  1  1
 * 1  1  1  1  1
 * 1  0  0  1  0
 *
 * dp:
 * 1  0  1  0  0
 * 1  0  1  1  1
 * 1  1  1  2  2
 * 1  0  0  1  0
 */

class Solution {
// #1 Brute Force + DP
    int maximalSquare1(vector<vector<char>>& matrix) {
	int M=matrix.size();
	if (M==0) return 0;
	int N=matrix[0].size();
	
	// key point to understand brute force:
	// sum[i][j] represents all 
	auto sum=vector<vector<int>>(M+1,vector<int>(N+1,0)); // sum[i][j]
	
	// Build
	for (int i=1; i<M+1; i++)
	    for (int j=1; j<N+1; j++) {
		// treat sum[i][j] as low-right corner
		// just check each iterations
		// for instance: a 2x2 matrix...
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1]-'0'; // - '0' because elem of matrix is char
	    }
	    
	int result = 0;
	
	for (int i=1; i<M+1; i++)
	    for (int j=1; j<N+1; j++) {
		int k=1;
		while (j-k>=0 && i-k>=0) {
		    // understand carefully!
		    int temp = sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
		    if (temp == k*k)
			// if it is a square
			result = max(result, temp);
		    k++;    
		}
	    }
	    
	return result;
    }

    // #2 DP
    int maximalSquare2(vector<vector<char>>& matrix) {
	int H = matrix.size();
	int W = matrix[0].size();
	if (H == 0 || W == 0) {
	    return 0;
	}
	vector<vector<int>> dp(H, vector<int>(W)); // dp[i][j] -- best square ending at (i, j)
	int answer = 0;

	for (int row = 0; row < H; ++row) {
	    for (int col = 0; col < W; ++col) {
		// we only check valid end point
		if (matrix[row][col] == '1') {
		    dp[row][col] = 1;
		    if (row > 0 && col > 0) {
			// most important part
			dp[row][col] += min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]});
		    }
		    answer = max(dp[row][col], answer);
		}
	    }
	}
	return answer;
    }
};
