/* 
 * LeetCode 547 Number of Privinces
 * Medium
 * Jiawei Wang
 * 2021.11.23
 */

#include <vector>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    // Union Find
    int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();

	for (int i = 0; i < n; i++) {
	    Father.push_back(i);
	}

	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		if (isConnected[i][j] == 0) continue; // just a lonely privince

		if (FindFather(i) != FindFather(j)) {
		    Union(i, j); // just set
		}
	    }
	}

	unordered_set<int> Set;
	for (int i = 0; i < n; i++) {
	    Father[i] = FindFather(i); 
	    Set.insert(Father[i]);
	}

	return Set.size();
    }

private:
    vector<int> Father;
    int FindFather(int x) {
	// iteration and update (usually after Union)
	if (Father[x] != x) {
	    Father[x] = FindFather(Father[x]);
	}

	// till (Father[x] == x) Key
	return Father[x];
    }

    void Union(int x, int y) {
	// Father[x] = Father[y] = min(Father[x], Father[y])
	x = Father[x];
	y = Father[y];
	if (x < y) Father[y] = x;
	else Father[x] = y;
    }
};
