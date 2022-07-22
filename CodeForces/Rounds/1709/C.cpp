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
  string BS;
  cin >> BS;

  int num = 0;
  vector<int> sums1 = {};
  vector<int> sums2 = {};



  for (char c : BS) {
    if (c == '(') num++;
    else if (c == ')') num--;
    sums1.push_back(num);
  }

  int curr = 0;

  for (int i = BS.size()-1; i >= 0; i--) {
    char c = BS[i];
    if (c == '(') curr++;
    else if (c == ')') curr--;
    sums2.push_back(curr);
  }

  int prv = INT_MIN;
  for (int i = 0; i < BS.size(); i++) {
    char c = BS[i];
    if (c == '?') {
      int target = sums1[i] + sums2[i];
      if (prv == INT_MIN) prv = target;
      else {
	if (prv != target) {
	  cout << "NO" << endl;
	  return;
	}
      }
    }
  }

  cout << "YES" << endl;
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

