/*
 * 1539B Love Song
 * CFDP Day 3
 * 2022.08.18
 * Angold Wang
 */

#include <iostream>
#include <string>
#include <vector>

using namespace ::std;

string s;
vector<vector<int>> dp;

int helper(int i, int j) {
  if (dp[i][j] != 0) {
    return dp[i][j];
  }

  int ans;
  int lres = (int)((char)s[i - 1]) - 'a' + 1;
  int rres = (int)((char)s[j - 1]) - 'a' + 1;

  if (i == j) {
    ans = lres;
  } else if ((j - i) == 1) {
    ans = helper(i + 1, j) + lres;
  } else {
    ans = helper(i + 1, j - 1) + lres + rres;
  }

  dp[i][j] = ans;
  return ans;
}

int main1() {
  int N, Q;
  cin >> N >> Q;
  cin >> s;

  dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

  int i, j;
  while (Q--) {
    cin >> i >> j;
    cout << helper(i, j) << '\n';
  }
}

int main() {
  // just prefix sum
  int N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;
  int dp[N + 1];
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i - 1] + (int)(s[i - 1] - 'a') + 1;
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l - 1] << endl;
  }
  return 0;
}
