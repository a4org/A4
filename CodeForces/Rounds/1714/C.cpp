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
  int s; cin >> s;

  string ret = "";
  for (int i = 9; i > 0; i--) {
    if (s >= i) {
      ret += to_string(i);
      s -= i;
    }
  }

  sort(ret.begin(), ret.end());
  cout << ret << endl;
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

