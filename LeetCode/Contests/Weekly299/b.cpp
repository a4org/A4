#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
  int countHousePlacements(int n) {

    if (n == 0) return 1;

    int ret = 0;
    vector<long long> dp(n + 1, 0);
    // dp[i] represents the number of ways that house can be placed on one side of the street
    dp[0] = 1;
    dp[1] = 2;


    for (int i = 2; i <= n; i++) {
      // for each size;
      dp[i] = dp[i-1] + dp[i-2];
      dp[i] = dp[i] % 1000000007;
    }

    return (dp[n] * dp[n]) % (1000000007);
  }
};

