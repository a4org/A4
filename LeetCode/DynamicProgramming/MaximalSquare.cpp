/*
 * LeetCode 221 Maximal Square
 * Medium
 * Jiawei Wang
 * 2021 6.13
 */

#include <iostream>
#include <vector>

using namespace::std;

// #1 Brutal
/*
 *
 */


// #2 Dynamic Programming
/*
 * dp[i][j] represents the maximum side length of the square with (i, j) in the lower right corner
 *
 * if dp[i][j] == 1:
 * dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
 *
 */

int maximalSquare1(vector<vector<char>>& matrix) {
        int M=matrix.size();
        if (M==0) return 0;
        int N=matrix[0].size();
        
        auto sum=vector<vector<int>>(M+1,vector<int>(N+1,0));
        
	// Build
        for (int i=1; i<M+1; i++)
            for (int j=1; j<N+1; j++) {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1]-'0'; // - '0' because elem of matrix is char
            }
            
        int result = 0;
        
        for (int i=1; i<M+1; i++)
            for (int j=1; j<N+1; j++) {
                int k=1;
                while (j-k>=0 && i-k>=0) {
                    int temp = sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
                    if (temp == k*k)
                        result = max(result, temp);
                    k++;    
                }
            }
            
        return result;
    }

int maximalSquare2(vector<vector<char>>& matrix) {
    int M = matrix.size();
    if (M == 0) return 0;
    int N = matrix[0].size();
    auto dp = vector<vector<int>>(M+1, vector<int>(N+1, 0));
    int result = 0;

    for (int i = 1; i <= M; i++) {
	for (int j = 1; j <= N; j++) {
	    if(matrix[i-1][j-1] == '0') {
		dp[i][j] = 0;
	    } else {
		int temp = min(dp[i-1][j], dp[i][j-1]);
		temp = min(temp, dp[i-1][j-1]);
		dp[i][j] = temp+1;
		result = max(result, dp[i][j]*dp[i][j]);
	    }
	}
    }
    return result;

}
