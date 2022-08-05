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

void run_case() {
  int N, H, M;
  cin >> N >> H >> M;
  int sleep = 60 * H + M; // sleep time in seconds
  int ans = 1e9;

  for (int i = 0; i < N; i++) {
    cin >> H >> M;
    int alarm = 60 * H + M;
    ans = min(ans, (alarm + 1440 - sleep) % 1440);
  }

  cout << ans / 60 << ' ' << ans % 60 << '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

