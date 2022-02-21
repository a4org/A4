/*
 * LeetCode 1986 Minimum Number of Work Secssions to Finish the Tasks
 * Medium
 * Jiawei Wang
 * 2022 2.22
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // BitMask + DP
    int minSessions(vector<int>& tasks, int sessionTime) {
	// Data-independent (sorting did not make any sense)
	int n = tasks.size();
	vector<int>dp(1<<n, INT_MAX/2);

	for (int state = 0; state < (1<<n); state++) {
	    // check all states 2^n
	    int sum = 0;
	    for (int i = 0; i < n; i++) {
		if ((state>>i)&1) {
		    // if we pick state i in current dp
		    sum += tasks[i];
		}
	    }
	    if (sum <= sessionTime) {
		dp[state] = 1;
	    }
	}

	for (int state = 0; state < (1<<n); state++) {
	    // for each state
	    // starting from maximum state i.e. 1001011 
	    // then only valid with those 1s, 0s are ignored
	    for (int subset = state; subset > 0; subset = (subset-1)&state) {
		dp[state] = min(dp[state], dp[subset] + dp[state-subset]);
	    }
	}

	return dp[(1<<n)-1];
    }
};

