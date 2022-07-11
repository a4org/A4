/* 
 * LeetCode 310 Minimum Height Trees
 * Medium
 * Jiawei Wang
 * 2021.9.2
 */

#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace::std;

class Solution {
public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    // Basic BFS

    unordered_set<int> forbset = {};

    for (int f : forbidden) {
      forbset.insert(f);
    }

    unordered_map<int, int> backnums(x+a, 0); // count back nums at each position
    // repeats are allowed

    vector<int> nw, before;

    before.push_back(1);

    int current;
    int ret = 0;

    while (!before.empty()) {
      // do bfs

      nw = {};
      ret++;
      
      for (int current : before) {
	int f = current + a; 
	int b = current - b;

	if (backnums[current] < 2) {
	  if (b >= 0 && forbset.find(b) == forbset.end()) {
	    nw.push_back(b);
	    backnums[b]++;
	    continue;
	  }
	}

	if (forbset.find(f) == forbset.end() && f <= x+a) {
	  backnums[b] = 0;
	  nw.push_back(f);
	  continue;
	}
      }

      before = nw;
    }

    return ret;
  }
};
