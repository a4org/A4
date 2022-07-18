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

void run_case() {
  int t;
  cin >> t; 
  int cc; // color code
  set<int> unic = {}; // unique color
  vector<vector<int>> colorpos(t+1, vector<int>()); // each position

  for (int i = 1; i <= t; i++) {
    cin >> cc;
    unic.insert(cc);
    colorpos[cc].push_back(i); // in order
  }

  for (int i = 1; i <= t; i++) {
    vector<int> curr = colorpos[i];

    if (unic.find(i) == unic.end()) {
      cout << 0 << " ";
      continue;
    }

    if (curr.size() == 1) {
      cout << 1 << " ";
      continue;
    }

    // odd: cannot connect
    // even: can connect

    int diff;
    int ret = 1;

    for (int j = 0; j < curr.size()-1; j++) {
      curr[j] = curr[j+1] - curr[j] - 1; // diff
    }

    diff = curr[0];

    bool pre = false;

    if (diff % 2 == 0) {
      ret++;
      pre = true;
      diff = 0;
    }

    for (int c = 1; c < curr.size()-1; c++) {
      diff += curr[c];
      if (!pre && diff % 2) {
	// previous is false, current is false too
	pre = true;
	ret++;
	diff = 0; // clear the diff
      } else if (diff % 2 == 0 && pre) {
	// all true
	diff = 0; // clear the diff
	ret++;
      } else {
	diff += 1; // count the current number
	// we cannot find answer here
	// just add the diff
	continue;
      }
    }

    cout << ret << " ";
  }
  cout << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

