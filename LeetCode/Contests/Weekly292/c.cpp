#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace::std;
using LL = long long;

class Solution {
public:
  int countTexts(string pressedKeys) {
    // block by block
    LL retl;
    int ret = 1;;
    LL mod = 1e9 + 7;
    vector<vector<int>> typecnt(2, vector<int>());
    unordered_set<int> thrset = {2, 3, 4, 5, 6, 8};
    unordered_set<int> furset = {7, 9};

    int cont = 1;
    if (pressedKeys.size() == 1) return 1;
    for (int i = 1; i < pressedKeys.size(); i++) {
      // divide them into groups
      if (pressedKeys[i] == pressedKeys[i-1]) {
	cont += 1;
      } else {
	int cntv = pressedKeys[i-1];
	if (thrset.find(cntv) != thrset.end()) typecnt[0].push_back(cont);
	else if (furset.find(cntv) != furset.end()) typecnt[1].push_back(cont);
	cont = 1;
      }
    }
    int cntv = pressedKeys.back();
    if (thrset.find(cntv) != thrset.end()) typecnt[0].push_back(cont);
    else if (furset.find(cntv) != furset.end()) typecnt[1].push_back(cont);

    unordered_map<int, int> thrmap = {};
    unordered_map<int, int> furmap = {};

    // DP
    // thrset
    for (int thrv : typecnt[0]) {
      if (thrmap.find(thrv) != thrmap.end()) {
	ret *= thrmap[thrv];
      } else {
	// calculate it
	
	
      }
    }
  } 
private:
  // Permutations
  int helper(int v, int n) {

  }
};
