/*
 * LeetCode 354 Russian Doll Envelopes
 * Hard
 * Jiawei Wang
 * 2022.5.7
 */


#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
  // Similar to LeetCode 300 Longest Increasing Subsequence (LIS)
public:
  // #1 DP II
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<int> dp(envelopes.size(), 1); // at least one
    // dp[i] the maximum length of RDS if i-th envelope is the largest one
    sort(envelopes.begin(), envelopes.end()); 
    // sort with the width (answer must in the subsequence)
    for (int i = 0; i < envelopes.size(); i++) {
      for (int j = 0; j < i; j++) {
	if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
	  // envelopes[i][0] may equal to envelopes[j][0]
	  dp[i] = max(dp[i], dp[j] + 1);
	}
      }
    }

    int ret = 1;
    for (auto len : dp) {
      ret = max(ret, len);
    }

    return ret;
  }

  // #1.5 Obtimized DP (configured sorting)
  int maxEnvelopes1(vector<vector<int>>& envelopes) {
    vector<int> dp(envelopes.size(), 1); // at least one
    // dp[i] the maximum length of RDS if i-th envelope is the largest one
    sort(envelopes.begin(), envelopes.end(), cmp); 
    // sort with the width (answer must in the subsequence)
    for (int i = 0; i < envelopes.size(); i++) {
      for (int j = 0; j < i; j++) {
	if (envelopes[i][1] > envelopes[j][1]) {
	  // envelopes[i][0] may equal to envelopes[j][0]
	  dp[i] = max(dp[i], dp[j] + 1);
	}
      }
    }

    int ret = 1;
    for (auto len : dp) {
      ret = max(ret, len);
    }

    return ret;
  }



  // #2 Greedy
  int maxEnvelopes2(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> q;
    for (auto x : envelopes) {
      if (q.empty() || x[1] > q.back()) { // cmp
	q.push_back(x[1]);
      } else {
	auto iter = lower_bound(q.begin(), q.end(), x[1]); 
	// find the lowest one in the queue and replace it
	*iter = x[1];
      }
    }
    return q.size();
  }

private:
  static bool cmp(vector<int>&a, vector<int>&b) {
    if (a[0] == b[0]) {
      // handle this cases in order to simplify every for loop
      return a[1] > b[1];
    }
    else {
      return a[0] < b[0];
    }
  }
};
