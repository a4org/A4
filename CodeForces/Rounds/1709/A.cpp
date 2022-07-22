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
  int hand;
  cin >> hand;

  vector<int> keys(4, 0);
  vector<int> doors(4, 0);

  keys[hand] = 1;
  int tmp;

  for (int i = 1; i <= 3; i++) {
    cin >> tmp;
    doors[i] = tmp;
  }

  for (int i = 2; i <= 3; i++) {
    hand = doors[hand];
    keys[hand] = 1;
  }

  for (int i = 1; i <= 3; i++)
    if (!keys[i]) {
      cout << "NO" << endl;
      return;
    }

  cout << "YES" << endl;
}


int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

