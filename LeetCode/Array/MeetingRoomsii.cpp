/*
 * LeetCode 253 Meeting Rooms ii
 * Medium
 * Jiawei Wang
 * 2022.5.10
 */


#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 1) return 1;

    int ret = 1;

    sort(intervals.begin(), intervals.end());
     
    int start = intervals[0][0];

    int end = 0;
    for (auto value : intervals) {
      int v = value[1];
      end = max(end, v);
    }

    // merge the interval first (to avoid the boundary cases)
    int ms = intervals[0][0]; // merge begin
    int me = intervals[0][0]; // merge end


    vector<vector<int>> mergedIntervals = {{ms, me}};

    for (int i = 1; i < n; i++) {
      int mis = intervals[i][0];
      int mie = intervals[i][1];

      if (me == mis) {
	// can merge them (continuous)
	mergedIntervals.back() = {ms, mie};
      } else {
	mergedIntervals.push_back({mis, mie});
      }
      ms = mis;
      me = mie;
    }

    n = mergedIntervals.size();

    // [start, end]
    int tmp = 0;
    for (int v = start; v <= end; v++) {
      tmp = 0;
      for (int i = 0; i < n; i++) {
	int s = mergedIntervals[i][0];
	int e = mergedIntervals[i][1];
	if (s > v) {
	  // Termination Condition
	  ret = max(ret, tmp);
	  break;
	} else if (s <= v && v <= e) {
	  // find one
	  tmp++;
	}
	ret = max(ret, tmp);
      }
    }
    ret = max(ret, tmp);

    return ret;
  }
};
