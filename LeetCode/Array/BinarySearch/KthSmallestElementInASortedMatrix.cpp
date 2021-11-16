/*
 * LeetCode 378 Kth Smallest Element in a Sorted Matrix
 * Medium
 * Jiawei Wang
 * 2021.11.16
 */

// Combine LeetCode 74 Search a 2D Matrix and LeetCode 240 Search a 2D Matrix ii

#include <vector>

using namespace::std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k ) {
	// Binary Search Like LeetCode 74
	long lower = INT_MIN;
	long upper = INT_MAX;

	while (lower < upper) {
	    long mid = lower + (upper - lower) / 2; // guess a number between INT_MIN and INT_MAX
	    int count = countSmallerOrEqual(mid, matrix);
	    if (count < k) {
		lower = mid+1;
	    } else {
		upper = mid;
	    }
	}
	return lower;
    }

private:
    int countSmallerOrEqual(int m, vector<vector<int>>& matrix) {
	// Property of this matrix
	// return the num of numbers that smaller (or equal) than m
	// Like LeetCode 240 
	// Starting from lower-left corner
	int n = matrix.size();
	int i = n-1, j = 0, count = 0;
	while (i >= 0 && j < n) {
	    if (matrix[i][j] <= m) {
		count += (i+1); // Key: this col (top to current i)
		j++; // go right (next col)
	    } else {
		i--; // go up
	    }
	}
	return count;
    }
};
