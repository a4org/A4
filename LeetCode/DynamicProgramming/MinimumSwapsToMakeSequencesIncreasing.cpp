/*
 * LeetCode 801 Minimum Swaps to Make Sequences Increasing
 * Hard
 * Jiawei Wang
 * 2021 8.16
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 DFS (TLE)
    int minSwap1(vector<int>& A, vector<int>& B) {
	int ans = INT_MAX;
	dfs(A, B, 1, 0, ans);
	return ans;
    }

    // #2 DP
    // list all possible statue each steps 
    int minSwap2(vector<int>& A, vector<int>& B) {
	const int n = A.size();
	// keep[i] -> the minimum swap times after we choose do not swap at index i
	vector<int> keep(n, INT_MAX);  

	// swap[i] -> the minimum swap times after we choose to swap at index i
	vector<int> swap(n, INT_MAX);

	keep[0] = 0;
	swap[0] = 1;

	for (int i = 1; i < n; ++i) {
	    if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
		// okay with our rule 
		// you can either choose swap or not swap
		// two possible cases: 
		
		// #1 do not swap
		keep[i] = keep[i - 1]; // do not swap
 
		// #2 swap (only one possible case to cause this)
		// --> A[i-1] and B[i-1] are swapped (at this time the if statement will may become not true)
		// then we swap A[i], B[i] as well
		swap[i] = swap[i - 1] + 1; 
	    }
	    if (B[i] > A[i-1] && A[i] > B[i-1]) {
		// also two possible cases in this if stmt
		
		// #1 We can make till i increasing by just swapping A[i], B[i]
		swap[i] = min(swap[i], keep[i - 1] + 1); 

		// #2 in this case, we swap A[i-1], B[i-1]. then the sequence till i become increasing
		keep[i] = min(keep[i], swap[i - 1]);
	    }
	}
	return min(keep.back(), swap.back());
    }
private:
    void dfs(vector<int>& A, vector<int>& B, int i, int c, int& ans) {
	// i -> times of recursion
	// c -> number of operations
	// ans -> the current minimum noo
	if (c >= ans) return;  // if c is larger than ans(prev) we do not need to keep searching (not optimal)

	if (i == A.size()) {
	    // search to the end
	    ans = min(ans, c);
	    return;
	}
	// Notice: The test cases are generated so that the given input always makes it possible
	// So no other cases (Only the following two)

	if (A[i] > A[i - 1] && B[i] > B[i - 1]) dfs(A, B, i + 1, c, ans); // okay with our rule

	if (A[i] > B[i-1] && B[i] > A[i - 1]) {
	    // only in this case you can swap
	    swap(A[i], B[i]);
	    dfs(A, B, i + 1, c + 1, ans);
	    swap(A[i], B[i]); // swap to origin (there are also other dfs path will reach here)
	}
    }
};



