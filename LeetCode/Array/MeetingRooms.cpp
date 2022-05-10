/*
 * LeetCode 252 Meeting Rooms
 * Easy
 * Jiawei Wang
 * 2022.5.10
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 1 || n == 0) return true;

    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; i++) {
      int s = intervals[i][0];
      int e = intervals[i][1];

      if (start == s || end > s) {
	return false;
      }

      start = s;
      end = e;
    }

    return true;
  }
};
