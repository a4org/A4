/*
 * LeetCode 2237 Count Positions on Street With Required Brightness
 * Medium
 * Jiawei Wang
 * 2022.5.22
 */

#include <vector>
#include <unordered_set>

using namespace::std;

class Solution {
public:
  int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
    vector<int> diff(n+2, 0);
    unordered_set<int> zero = {};

    for (vector<int> light : lights) {
      if (light[1] == 0) {
	diff[light[0]]++;
	zero.insert(light[0]);
      } else {
	diff[max(light[0]-light[1], 0)]++;
	diff[min(light[0]+light[1]+1, n)]--;
      }
    }

    int curr = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      int req = requirement[i];
      curr += diff[i];
      if (curr >= req) ret++;
      if (zero.find(i) != zero.end()) curr--;
    }

    return ret;
  }
};
