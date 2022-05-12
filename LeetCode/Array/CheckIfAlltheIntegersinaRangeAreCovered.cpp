/*
 * LeetCode 1893 Check if All the Integers in a Range Are Covered
 * Easy
 * Jiawei Wang
 * 2022.5.12
 */

#include <vector>

using namespace::std;

class Solution {
public:
  // #1 brute force
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    for (int s = left; s <= right; s++) {
      bool find = false;
      for (auto range : ranges) {
	find = false;
	if (range[0] <= s && range[1] >= s) {
	  find = true;
	  break;
	}
      }
      if (!find) return false;
    }
    return true;
  }

  // #2 Line sweep (like 253 meeting rooms ii)
  bool isCoveredii(vector<vector<int>>& ranges, int left, int right) {
    int rge[52] = {};
    for (auto &range : ranges) {
      rge[range[0]] += 1;
      rge[range[1]+1] -= 1;
    }

    for (int i = 1, overlaps = 0; i <= right; ++i) {
      overlaps += rge[i];
      if (i >= left && overlaps == 0) {
	return false;
      }
    }

    return true;
  }
};


