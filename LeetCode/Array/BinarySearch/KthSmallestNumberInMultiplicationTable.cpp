/*
 * LeetCode 668 Kth Smallest Number in Multiplication Table
 * Hard
 * Jiawei Wang
 * 2021.11.16
 */
#include <vector>

using namespace::std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
	int left = 1;
	int right = m*n;

	while (left < right) {
	    int val = left - (right-left)/2;

	    if (countEqualOrSmaller(val, m, n) < k) {
		left = val + 1;
	    } else {
		right = val;
	    }
	}
	return left;

    }
private:
    int countEqualOrSmaller(int val, int m, int n) {
	// check how many numbers that 
	int count = 0;
	for (int i = 1; i <= m; i++) {
	    count += min(n, val/i); // every lines
	}
	return count;
    }
};
