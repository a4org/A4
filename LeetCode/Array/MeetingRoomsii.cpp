/*
 * LeetCode 253 Meeting Rooms ii
 * Medium
 * Jiawei Wang
 * 2022.5.10
 */

#include <vector>
#include <map>

using namespace::std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> m;
    // default value is zero
    for (auto &t : intervals)
      m[t[0]]++, m[t[1]]--;

    // Save all time points and change on current meeting rooms


    // think easy, brute force is simple actually, but sometimes
    // it is awful and meaniness if you think too much

    // very brilliant and natual idea:
    // when a meeting start, at this time we increase the count
    // when it end we decrease the count
    // and then we track the change of #rooms in time order
    // which ret is the peak count of a specific time
    int cur = 0, res = 0;
    for (auto &it : m)
      res = max(res, cur += it.second);
    return res;
  }
};
