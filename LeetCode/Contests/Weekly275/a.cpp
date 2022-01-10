#include <vector>
#include <unordered_set>
#include <string>

using namespace::std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
	for (auto m : matrix) {
	    // col
	    unordered_set<int> ms;
	    for (int mi : m) {
		ms.insert(mi);
	    }
	    if (ms.size() != m.size()) return false;
	}

	for (int i = 0; i < matrix.size(); i++) {
	    unordered_set<int> us;
	    for (auto m : matrix) {
		int mi = m[i];
		us.insert(mi);
	    }
	    if (us.size() != matrix.size()) return false;
	}

	return true;
    }
};

