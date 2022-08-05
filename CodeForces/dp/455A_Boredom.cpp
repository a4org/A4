/*
 * 455A Boredom
 * CFDP Day 1
 * 2022.08.05
 * Angold Wang
 */

#include <cstring>
#include <iostream>

using namespace::std;

const int N = 1000010;

int cnt[N];
long long dp[N];

int main() {
  int n; cin >> n;
  // The memset() function in C++ copies a single character for a specified number of time to an object.
  memset(cnt, 0, sizeof(cnt));

  int maxn = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    cnt[foo]++;
    maxn = max(foo, maxn);
  }

  dp[0] = 0;
  dp[1] = cnt[1];

  for (int i = 2; i <= maxn; i++) {
    dp[i] = max(dp[i-1], dp[i-2] + (long long)i*cnt[i]);
  }

  cout << dp[maxn] << '\n';
}

/*
 * Key: CFDP
 * ak, delete ak+1, ak-1
 * means the "isolation" sequence
 * DP, think more
 * - Angold, 2022.8.5
 */
