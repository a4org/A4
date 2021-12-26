/*
 * LeetCode 973 K Closest Points to Origin
 * Medium
 * Jiawei Wang
 * 2021.12.26
 */


#include <vector>
#include <queue>

using LL = long long;
using namespace::std;

class Solution {
    vector<int> next[100]; // 100 vector<int>
public:
    // BFS O(n^3)
    int maximumDetonation(vector<vector<int>>& bombs) {
	int n = bombs.size();
	for (int i = 0; i < n; i++) {
	    // for every bombs
	    for (int j = 0; j < n; j++) {
		// check its distance with others
		LL dx = bombs[i][0] - bombs[j][0];
		LL dy = bombs[i][1] - bombs[j][1];
		LL r = bombs[i][2];
		if (dx*dx + dy*dy <= r*r) {
		    // if in area, then push_back into its next
		    next[i].push_back(j);
		}
	    }
	}

	int ret = 0;
	// BFS
	for (int s = 0; s < n; s++) {
	    queue<int> q;
	    q.push(s);
	    vector<int> visited(n);
	    visited[s] = 1;

	    while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int c : next[curr]) {
		    if (visited[c]) continue;
		    q.push(c);
		    visited[c] = 1;
		}
	    }
	    int count = 0;
	    for (int i = 0; i < n; i++) {
		count += visited[i];
	    }

	    ret = max(count, ret);
	}

	return ret;
    }
};
