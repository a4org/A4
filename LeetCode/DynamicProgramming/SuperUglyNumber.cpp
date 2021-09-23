/*
 * LeetCode 313 Super Ugly Number
 * Medium
 * Jiawei Wang
 * 2021 9.23
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
	// all Super Ugly Numers comes from other sunums
	vector<int> SUnums = {1}; // store all SUnums
	vector<int> PrimeTimes(primes.size(), 0); // PrimeTimes[i] is the caculated index of primes[i]  
	if (n == 2) return *min_element(primes.begin(), primes.end());

	for (int i = 0; i < n-1; i++) {
	    // build the SUnums array (the first element always will be 1)
	    int min_num = INT_MAX;
	    for (int j = 0; j < primes.size(); j++) {
		// get the current minimum number
		int curr = SUnums[PrimeTimes[j]] * primes[j]; 
		if (curr < min_num) {
		    min_num = curr;
		}
	    }
	    // ++ all valid prime nums index
	    for (int k = 0; k < primes.size(); k++) {
		if (SUnums[PrimeTimes[k]] * primes[k] == min_num) PrimeTimes[k]++;
	    }
	    SUnums.push_back(min_num);
	}
	return SUnums[n-1];
    }
};

