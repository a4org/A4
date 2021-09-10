/*
 * LeetCode 413 Arithmetic Slices
 * Medium
 * Jiawei Wang
 * 2021 9.9
 */

#include <vector>

using namespace::std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ending with A[i] (size == 3)
	// or the current valid slice size - 3
        if (A[2]-A[1] == A[1]-A[0]) dp[2] = 1;
        int result = dp[2];
        for (int i = 3; i < n; ++i) {
	// if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
	// equals to:
	//      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
	//      +
	//      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
	// it is how dp[i] = dp[i-1] + 1 comes
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) 
                dp[i] = dp[i-1] + 1; // add the brand new slice (size == 3)
	    // append a new valid number

            result += dp[i]; // key: 
	    // *  *  *
	    // *  *  *  *
	    // *  *  *  *  *
	    // *  *  *  *  *  *
	    // Every time we append a valid int to the end, each size of sub slices (layers) (from 3 to dp[i]) add 1
        }
        return result;
    }
};
