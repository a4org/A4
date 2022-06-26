#include <vector>

using namespace::std;

class Solution {
public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    // brute force
    int n = grid[0].size() - 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
	if (isDiagonals(n, i, j) && grid[i][j] == 0) {
	  return false;
	}

	if (!isDiagonals(n, i, j) && grid[i][j] != 0) {
	  return false;
	}
      }
    }

    return true;
  }

private:
  bool isDiagonals(int n, int i, int j) {
    if (i == j) {
      return true;
    }

    else if (n - i == j || n - j == i) return true;

    return false;
  }
};
