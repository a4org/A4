/*
 * LeetCode 759 Employee Free Time
 * Hard
 * Jiawei Wang
 * 2022.5.16
 */

#include <vector>
#include <algorithm>

using namespace::std;

// Definition for an Interval.
class Interval {
public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

static bool cmp(pair<int, int>&a, pair<int, int>&b) {
  if (a.first != b.first) return a.first < b.first;
  else return a.second > b.second;
}

class Solution {
public:
  // sequencial scan diff array
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<pair<int, int>> diff; // {time, incremental +1/-1}
    for (int i = 0; i < schedule.size(); i++) {
      for (auto range : schedule[i]) {
	diff.push_back({range.start, +1});
	diff.push_back({range.end, -1});
      }
    }

    sort(diff.begin(), diff.end(), cmp);
    // simulating the time

    int count = 0;
    int start = -1, end = -1;

    vector<Interval> ret = {};

    for (auto d : diff) {
      count += d.second;
      if (d.second == -1 && count == 0) {
	// interval begin (1 -> 0)
	start = d.first;
      }
      else if (d.second == 1 && count == 1 && start != -1) {
	// interval end (0 -> 1)
	end = d.first;
	if (start == end) continue;
	ret.push_back({start, end});
      }
    }

    return ret;
  }
};
