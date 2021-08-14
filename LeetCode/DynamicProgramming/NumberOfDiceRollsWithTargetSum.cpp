/*
 * LeetCode 1155  Number of Dice Rolls with Target Sum
 * Medium
 * Jiawei Wang
 * 2021 8.14
 */

#include <vector>

using namespace::std;

class Solution {
const int mod = 1e9 + 7;
public:
    // #1 Basic DP
    int numRollsToTarget1(int d, int f, int target) {
	// dp[s]: the number of ways to get sum 's' so far
	vector<int> ways(target + 1);
	ways[0] = 1; // only one way to get sum 0
	for (int rep = 1; rep <= d; ++rep) {
	    // in each rep; ways tells the number of ways till this rep start
	    // and new_ways tells records current rep's ways
	    // new_ways(already + pipes) += ways[already]
	    vector<int> new_ways(target+1);
	    for (int already = 0; already <= target; ++already) {
		for (int pipes = 1; pipes <= f; ++pipes) {
		    if (already + pipes <= target) {
			int& tmp = new_ways[already + pipes];
			tmp += ways[already];
			if (tmp >= mod) {
			    tmp -= mod;
			}
		    }
		}
	    }
	    ways = new_ways;
	}
	return ways[target];
    }

    void add(int& a, int& b) {
	a += b;
	if (a >= mod) {
	    a -= mod;
	}
    }

    // #2 dp using prefix sum
    int numRollsToTarget2(int d, int f, int target) {
	vector<int> ways(target+1);
	ways[0] = 1;
	for (int rep = 1; rep <= d; ++rep) {
	    for (int i = 1; i <= target; ++i) {
		add(ways[i], ways[i-1]); // computes prefix sum
	    }
	    vector<int> new_ways(target + 1);
	    // new_ways[s]: the number of ways to get sum 's' so far
	    for (int new_sum = 1; new_sum <= target; ++new_sum) {
		// get (new_sum-f ... new_sum-1)
		new_ways[new_sum] = ways[new_sum - 1] - (new_sum - f - 1 >= 0 ? ways[new_sum - f - 1] : 0); 

		if (new_ways[new_sum] < 0) {
		    new_ways[new_sum] += mod;
		}
	    }
	    ways = new_ways; 
	}
	return ways[target]; // final return actually new_ways
    }
};

