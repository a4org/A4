#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifdef DEBUG
  #define debug(args...)            {dbg, args; cerr<<endl;}
#else
  #define debug(args...)            // Just strip off all debug tokens
#endif

struct debugger
{
  template<typename T> debugger& operator , (const T& v)
  {    
    cerr << v << " ";    
    return *this;    
  }
} dbg;

const int INF = int(1e9) + 5;

void run_case() {
  // DP
  string T;
  int N;
  cin >> T >> N;
  vector<string> S(N);
  for (auto &s : S) {
    cin >> s;
  }

  int L = int(T.size());
  vector<int> dp(L+1, INF);
  vector<int> previous(L+1, -1);
  vector<int> previous_which(L+1, -1);
  vector<int> previous_start(L+1, -1);
  dp[0] = 0;

  for (int len = 0; len < L; len++) {
    for (int i = 0; i < N; i++) {
      int s_len = int(S[i].size());

      for (int start = max(len - s_len, 0); start <= min(L - s_len, len); start++) {
	if (T.compare(start, s_len, S[i]) == 0) { // 0 means equal
	  if (dp[len] + 1 < dp[start + s_len]) {
	    dp[start + s_len] = dp[len] + 1;
	    previous[start + s_len] = len; // record its length
	    previous_which[start + s_len] = i; // index
	    previous_start[start + s_len] = start;
	  }
	}
      }
    }
  }

  if (dp[L] >= INF) {
    // we cannot reach here
    cout << -1 << '\n';
    return;
  }

  cout << dp[L] << '\n';
  int end = L;

  while (end > 0) {
    int which = previous_which[end];
    int start = previous_start[end];
    cout << which + 1 << ' ' << start + 1 << '\n';
    end = previous[end];
  }

}

int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

