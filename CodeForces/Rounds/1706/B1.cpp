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
using namespace std;

#ifdef DEBUG
    #define debug(args...)            {dbg, args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << " ";    
        return *this;    
    }
} dbg;

int n;
const int MAXN = 100100; // 1e5 -> Maximum # of blocks
int dp[2][MAXN]; // dp[i][c] := Maximum # of color c of odd(i==1)/even(i==0) parties 

void run_case() {

  cin >> n;

  // init
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    int x; cin >> x; // x := current color
    dp[i & 1][x] = max(dp[i & 1][x], dp[(i ^ 1) & 1][x] + 1);
    /* Accumulated
     * max # of block on ith pos in color x 
     * => max (# of accumulated different parties + 1), (# of accumulated same parties).
     */
  }

  for (int i = 1; i <= n; i++) {
    cout << max(dp[0][i], dp[1][i]) << " ";
  }

  cout << endl;
}

int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

