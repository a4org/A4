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

const int MAXN = 100100;
vector<int> a[MAXN];

int solve(int x) {
  if (!a[x].size()) return 0;

  int curr = a[x][0];
  int ans = 1;

  for (int i : a[x]) {
    if ((i & 1) != (curr & 1)) {
      // in the differnet parities
      ans++;
      curr = i;
    }
  }

  return ans;
}

void run_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i].clear(); // make this container size zero
  }

  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[x].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << solve(i) << " ";
  }
  cout << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

