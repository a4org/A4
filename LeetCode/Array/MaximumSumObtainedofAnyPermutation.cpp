/*
 * LeetCode 1589 Maximum Sum Obtained of Any Permutation
 * Medium
 * Jiawei Wang
 * 2022.5.19
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
  int mod = 1000000007;
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    // Diff array
    int n = nums.size();
    vector<long> diff(n+2, 0);

    for (auto request : requests) {
      diff[request[0]]++;
      diff[request[1]+1]--;
    }

    for (int i = 1; i < n; i++) {
      diff[i] += diff[i-1];
    }

    sort(diff.rbegin(), diff.rend());
    sort(nums.rbegin(), nums.rend());

    long ret = 0;
    for (int i = 0; i < n; i++) {
      if (diff[i] == 0) break;
      int over = diff[i] * nums[i];
      over %= mod;
      ret += over;
    }

    return ret % mod;
  }
};
