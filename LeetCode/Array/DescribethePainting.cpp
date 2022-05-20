/*
 * LeetCode 1943 Describe the Painting
 * Medium
 * Jiawei Wang
 * 2022.5.20
 */

#include <vector>
#include <map>

using namespace::std;

using LL = long long;

class Solution {
public:
  vector<vector<LL>> splitPainting(vector<vector<int>>& segments) {
    map<LL, LL> diffPairs = {};

    for (auto seg : segments) {
      diffPairs[seg[0]] += seg[2];
      diffPairs[seg[1]] -= seg[2];
    }

    LL start = -1, end = -1;
    LL sum = 0;

    vector<vector<LL>> ret = {};

    // map is already sorted
    // 1. No need to find n
    // 2. Each diff pair is considered individually
    // if we do sequencial scan (from 0 to n)
    // we cannot handle the situation that the mixed color
    // value are the same but the color sets are different
    for (auto x : diffPairs) {
      int pos = x.first;
      LL diff = x.second;

      if (start == -1) {
	// last time it is a zero color region
	start = pos;
      } else {
	// individually
	// due to the mixed color rule (sets) and each colori is distinct
	// every time we meet another pos, we should append it to the ret
	// (unless the sum is zero)
	end = pos;
	ret.push_back({start, end, sum});
	start = end;
      }

      sum += diff;

      if (sum == 0)
	start = -1;
    }

    return ret;
  }
};

