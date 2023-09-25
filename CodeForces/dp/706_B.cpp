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
#include <sstream>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// https://codeforces.com/blog/entry/76087
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
  os << '{' << p.first << ", " << p.second << '}';
  return os;
}

template <typename C,
          typename T = std::decay<decltype(*begin(std::declval<C>()))>,
          typename std::enable_if<!std::is_same<C, std::string>::value>::type
              * = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container) {
  bool first = true;
  std::stringstream ss;
  ss << '[';
  for (const auto &x : container) {
    if (!first) {
      ss << ", ";
    }
    first = false;
    ss << x;
  }
  ss << ']';
  return os << ss.str();
}

vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}

void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef DEBUG
#define debug(...)                                                             \
  debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

/* O(nlgn) Time limit exceeded
void run_case(vector<int> shop) {
  int x;
  cin >> x;
  if (x < shop[0]) {
    cout << 0 << endl;
    return;
  }
  cout << upper_bound(shop.begin(), shop.end(), x) - shop.begin() << endl;
}
*/

int cost[100000];
// vector<int> cost(100000);
// if we define cost as a vector, the program might hehave unpredicatably.
// even if we define a vector with size n, the C++ compiler will allocate memory
// for the vector on the heap, but it is not guaranteed to be contiguous, which
// can cause issues when accessing elements of the vector.
int main() {
  // int cost[100000];
  // if we define cost inside the main function, the program might hehave
  // unpredicatably. that is because the stack size is limited.

  int n, x, q, m;
  cin >> n;
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cost[x]++;
    if (x > maxx)
      maxx = x;
  }

  for (int i = 1; i <= maxx; i++) {
    cost[i] += cost[i - 1];
  }

  cin >> q;
  while (q--) {
    cin >> m;
    if (m >= maxx)
      cout << n << endl;
    else
      cout << cost[m] << endl;
  }
  return 0;
}
