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
  int n, m;
  cin >> n >> m;
  vector<int> sequence = {};

  int curr;
  for (int i = 0; i < n; i++) {
    cin >> curr;
    sequence.push_back(curr);
  }


  string s = "";
  for (int i = 0; i < m; i++)
    s.push_back('B');


  int mnum;
  int pos;

  // greedy
  for (int num : sequence) {
    mnum = m + 1 - num;

    pos = min(num, mnum);

    if (s[pos-1] == 'A') {
      if (pos == num) {
	s[mnum-1] = 'A';
      } else {
	s[num-1] = 'A';
      }
    } else {
      s[pos-1] = 'A';
    }
  }

  cout << s << endl;
}


int main() {
    int tests;
    cin >> tests;

    while (tests-- > 0) 
	run_case();
}

