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

#define ll long long

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

ll buildings[100100];

ll get(int i) {
  return max(0ll, max(buildings[i - 1], buildings[i + 1]) - buildings[i] + 1);
  // long long zero
}


void run_case() {
  int N; cin >> N;
  int maxcool = (N-1) / 2;
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    buildings[i] = tmp;
  }

  ll ret = 0;

  if (N % 2) {
    // there is only one solution
    // just doing sequencial scan
    for (int i = 1; i < N-1; i+=2) {
      ret += get(i);
    }
    cout << ret << endl;
    return;
  }

  // when N is even, since we can only unselect one building to make it maximum
  // use prefix sum
  
  ret = 0;
  for (int i = 1; i < N-1; i+=2) {
    ret += get(i);
  }

  ll ans = ret;

  for (int i = N-2; i >= 1; i-=2) {
    ret -= get(i-1);
    ret += get(i);
    ans = min(ret, ans);
  }

  cout << ans << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

