/*
 * LeetCode 746 Min Cost Climbing Stairs
 * Easy
 * Jiawei Wang
 * 2021 10.5
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 Classic DP (Intuition)
    // Acutally: the two cases have no difference
    int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	if (n < 2) return 0; // start from 0 or 1
	if (n == 2) return min(cost[0], cost[1]);
	if (n == 3) return min(cost[0] + cost[2], cost[1]);

	vector<int> dp1(n+1); // the minimum cost to reach stair i with starting point 0
	vector<int> dp2(n+1); // the minimum cost to reach stair i with starting point 1

	// #1 start from index 0
	dp1[0] = 0;
	dp1[1] = cost[0];
	dp1[2] = cost[0];
	for (int i = 3; i <= n; i++) {
	    dp1[i] = min(dp1[i-1] + cost[i-1], dp1[i-2] + cost[i-2]);
	}
	
	// #2 Start from index 1
	dp2[0] = 0;
	dp2[1] = 0;
	dp2[2] = cost[1];
	dp2[3] = cost[1];
	for (int i = 4; i <= n; i++) {
	    dp2[i] = min(dp2[i-1] + cost[i-1], dp2[i-2] + cost[i-2]);
	}
	
	return min(dp1[n], dp2[n]);
    }


    // #2 Mem O(1) DP
    int minCostClimbingStairs2(vector<int>& cost) {
	int dp1 = 0;
	int dp2 = 0;

	for (int i = 2; i <= cost.size(); ++i) {
	    int dp = min(dp1 + cost[i-1], dp2 + cost[i-2]);
	    dp2 = dp1;
	    dp1 = dp;
	}
	return dp1;
    }

};


