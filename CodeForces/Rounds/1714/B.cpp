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
  vector<int> ints = {};
  int curr;

  int k = n;
  while (k--) {
    cin >> curr;
    ints.push_back(curr);
  }

  unordered_set<int> us = {};

  int ret = 0;
  for (int i = n-1; i >= 0; i--) {
    curr = ints[i];
    if (us.find(curr) != us.end()) {
      break;
    } else {
      us.insert(curr);
      ret++;
    }
  }
  cout << n-ret << '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

