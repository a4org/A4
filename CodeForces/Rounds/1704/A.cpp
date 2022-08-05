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

bool helper(char target, string sub) {
  for (char s : sub) {
    if (s == target) return true;
  }
  return false;
}


void run_case() {
  int n, m; cin >> n >> m;
  string a, b;
  cin >> a >> b;

  if (m == 1 && n > 1) {
    if (helper(b[0], a)) {
      cout << "YES" << '\n';
      return;
    }
  } else if (n == 1 && m > 1) {
    if (helper(a[0], b)) {
      cout << "YES" << '\n';
      return;
    }
  }

  if (m == n) {
    if (a != b) {
      cout << "NO" << '\n';
      return;
    } else {
      cout << "YES" << '\n';
      return;
    }
  } else if (n > m) {
    if (a.substr(n-m+1, m-1) == b.substr(1, m-1)) {
      if (helper(b[0], a.substr(0, n-m))) {
	cout << "YES" << '\n';
	return;
      }
    }
  } else {
    if (b.substr(m-n+1, n-1) == a.substr(1, n-1)) {
      if (helper(a[0], b.substr(0, m-n))) {
	cout << "YES" << '\n';
	return;
      }
    }
  }

  cout << "NO" << '\n';
}

int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

