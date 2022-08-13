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

  bool cycle = true; // flip

  int bt = 0;
  if (n % 2) {
    bt = 2;
  } else {
    bt = 1;
  }

  vector<int> ret = {};
  for (int i = n; i >= bt; i--) {
    if (cycle) {
      ret.push_back(i-1);
    } else {
      ret.push_back(i+1);
    }
    cycle = !cycle;
  }

  if (bt == 2) cout << 1 << " ";

  for (int i = ret.size()-1; i >= 0; i--) {
    cout << ret[i] << " ";
  }


  cout << '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

