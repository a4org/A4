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

// 4 -> 2 1 4 3
void run_case() {
  int N; cin >> N;

  if (N & 1) {
    // odd: #odd = #even + 1
    cout << 1 << " " << endl;
    for (int i = 3; i <= N; i+=2) {
      cout << i << " ";
      cout << i-1 << " ";
    }
  } else {
    // even: #odd == #even
    for (int i = 2; i <= N; i+=2) {
      cout << i << " ";
      cout << i-1 << " ";
    }
  }

  cout << '\n';
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

