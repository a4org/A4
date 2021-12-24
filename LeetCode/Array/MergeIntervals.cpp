/*
 * LeetCode 56 Merge Intervals
 * Medium
 * Jiawei Wang
 * 2021.12.24
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end()); // sort by the first element
	int n = intervals.size();

	if (n == 1) return intervals;

	vector<vector<int>> ret = {};

	int begin = (*intervals.begin())[0]; // curr
	int last  = (*intervals.begin())[1]; // [0. 1e4]

	for (int i = 1; i < n; i++) {
	    vector<int> inter = intervals[i];
	    if (inter[0] > last) {
		// Got an answer
		ret.push_back({begin, last});
		// update next
		begin = inter[0];
		last  = inter[1];
	    } else if (inter[0] <= last && inter[1] > last) {
		// merge an interval
		last = inter[1];
	    } 
	}
	if (ret.size() == 0 || ret.back()[0] != begin) {
	    ret.push_back({begin, last});
	}

	return ret;
    }
};
