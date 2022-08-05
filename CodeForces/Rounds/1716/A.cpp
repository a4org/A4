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
  int ret; int n; cin >> n;
  ret = INT_MAX;

  if (n == 1) {
    cout << 2 << '\n';
    return;
  }

  if (n % 3 == 0) ret = n/3;
  if (n % 2 == 0) ret = min(n/2, ret);

  if (n % 3 != 0) {
    ret = min(ret,  n/3 + (n%3==1?2:1));
  } 
  if (n % 2 != 0) {
    ret = min(ret, n/2 + 1);
  }

  cout << ret << '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

