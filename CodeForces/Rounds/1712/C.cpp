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
  int n; cin >> n;
  vector<int> vi(n);
  for (int &i : vi)
    cin >> i;

  int sz = vi.size();

  if (sz <= 1) {
    cout << 0 << '\n';
    return;
  }

  int currMax = vi[sz-1];
  unordered_map<int, int> usi = {{currMax, sz-1}};
  unordered_set<int> nsi = {};

  for (int i = sz-1; i >= 0; i--)
    nsi.insert(vi[i]);

  int kill = 0;
  for (int i = sz-2; i >= 0; i--) {
    if (vi[i] <= currMax) {
      currMax = vi[i];
      usi[vi[i]] = i;
    } else {
      kill = i;
      break;
    }
  }

  int tmp; int limit = -1;
  for (int i = 0; i <= kill; i++) {
    tmp = vi[i];
    if (usi.find(tmp) != usi.end() && usi[tmp] > i) {
      limit = max(limit, usi[tmp]);
    }
  }

  int overload = 0;
  for (auto it = usi.begin(); it != usi.end(); it++) {
    if (it->second <= limit) {
      overload++;
    }
  }
  cout << nsi.size() - usi.size() + overload<< '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

