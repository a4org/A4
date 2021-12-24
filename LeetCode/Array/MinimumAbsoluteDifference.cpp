/*
 * LeetCode 1200 Minimum Absolute Difference
 * Easy
 * Jiawei Wang
 * 2021.12.20
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ret;


	int m = INT_MAX;
	for (int i = 1; i < arr.size(); i++) {
	    // find min
	    int diff = arr[i] - arr[i-1];
	    m = min(diff > 0 ? diff : -1 * diff, m);
	}

	for (int i = 1; i < arr.size(); i++) {
	    int diff = arr[i] - arr[i-1];
	    if (diff == -m) {
		ret.push_back({arr[i], arr[i-1]});
	    } else if (diff == m) {
		ret.push_back({arr[i-1], arr[i]});
	    }
	}

	return ret;
    }
};
