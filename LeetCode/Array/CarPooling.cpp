/*
 * LeetCode 1094 Car Pooling
 * Medium
 * Jiawei Wang
 * 2022.5.14
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
  // diff array
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> diff;
    for (auto trip : trips) {
      diff.push_back({trip[1], trip[0]});
      diff.push_back({trip[2], -trip[0]});
    }

    sort(diff.begin(), diff.end()); 
    // sorting on pair will consider each element
    // will simulating a trip

    int num = 0;
    for (auto d : diff) {
      num += d.second;
      if (num > capacity) return false;
    }

    return true;
  }
};
