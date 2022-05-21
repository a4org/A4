/*
 * LeetCode 2251 Number of Flowers in Full Bloom
 * Hard
 * Jiawei Wang
 * 2022.5.21
 */

#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace::std;

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
    unordered_map<int, int> stored = {};
    vector<int> ret = {};
    map<int, int> diff = {};

    for (auto flower : flowers) {
      diff[flower[0]]++;
      diff[flower[1]+1]--;
    }

    int previous = 0;

    vector<int> spersons = persons;

    sort(spersons.begin(), spersons.end());

    map<int, int>::iterator last = diff.begin();
    for (int i = 0; i < persons.size(); i++) {
      int pp = spersons[i]; // person's position
      for (; last != diff.end(); last++) {
	if (pp < last->first) {
	  break;
	}
	previous += last->second;
      }
      stored[pp] = previous;
    }

    for (auto person : persons) {
      ret.push_back(stored[person]);
    }

    return ret;
  }
};

