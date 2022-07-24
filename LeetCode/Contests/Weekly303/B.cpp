#include <unordered_map>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      unordered_map<string, int> ss = {};
      int n = grid.size();
      int colg[n][n];
      int ret = 0;
      int j = 0;
      for (vector<int> g : grid) {
	string key = "";
	for (int i = 0; i < g.size(); i++) {
	  int row = g[i];
	  string srow = to_string(row);
	  key += srow;
	  key.push_back('_');
	  colg[i][j] = row;
	}

	if (ss.find(key) == ss.end()) {
	  ss[key] = 1;
	} else {
	  ss[key] += 1;
	}
	j++;
      }


      for (int i = 0; i < n; i++) {
	string key = "";
	for (int k = 0; k < n; k++) {
	  int row = colg[i][k];
	  string srow = to_string(row);
	  key += srow;
	  key.push_back('_');
	}
	if (ss.find(key) != ss.end()) {
	  ret += ss[key];
	}
      }

      return ret;
    }

};
