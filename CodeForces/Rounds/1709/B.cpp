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

vector<int> world = {};

void run_case() {
  int s, t;
  cin >> s >> t;
}

int main() {
  world.push_back(-1);


  // greedy
  int n, m;
  cin >> n >> m;

  int tmp;
  while (n--) {
    cin >> tmp;
    world.push_back(tmp);
  }


  while (m--) {
    run_case();
  }
}

