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
  vector<int> unhappy = {-1};
  map<int, set<int>> pairs = {};
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int tmp; cin >> tmp;
    unhappy.push_back(tmp);
  }

  while (m--) {
    int x, y; cin >> x >> y;
    pairs[x].insert(y);
    pairs[y].insert(x);
  }

  int numm = m;

  if (m & 1) {
    // we need to delete something

  } else {
    cout << 0;
  }

  cout << '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

