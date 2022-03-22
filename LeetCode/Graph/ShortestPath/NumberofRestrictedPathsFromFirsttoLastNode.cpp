/* 
 * LeetCode 1786 Number of Restricted Paths From First to Last Node
 * Medium
 * Jiawei Wang
 * 2022.3.21
 */

#include <vector>
#include <queue>

using namespace::std;

using LL = long long;
using PLL = pair<LL, LL>;

class Solution {
    LL distLast[20001];       // min distance to last node
    vector<PLL> adj[20001];   // dist to nearby node
    int resolved[20001];
    LL M = 1e9+7;
    int n;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
	this->n = n;
	// 0. initialize
	for (int i = 0; i <= n; i++) {
	    distLast[i] = -1;
	}

	for (auto edge : edges) {
	    int dist = edge[2]; int u = edge[0]; int v = edge[1];
	    adj[u].push_back({v, dist});
	    adj[v].push_back({u, dist});
	}

	// Dijkstra
	// 1. find the shortest path
	priority_queue<PLL, vector<PLL>, greater<>> pq; // {mindist, edge}
	pq.push({0, n});

	while (!pq.empty()) {
	    LL d = pq.top().first;  // dist
	    LL e = pq.top().second; // edge
	    pq.pop();

	    if (distLast[e] != -1) {
		continue;
	    }

	    distLast[e] = d; // min dist

	    for (auto x : adj[e]) {
		// get the next edge, from this on
		int edge = x.first;
		int dist = x.second;
		if (distLast[edge] != -1) continue;
		pq.push({dist+d, edge});
	    }
	}

	for (int i = 0; i <= n; i++) {
	    resolved[i] = -1;
	}

	// 2. dfs
	return helper(1);
    }

private:
    int helper(int curr) {
	LL total = 0;
	if (resolved[curr] != -1) {
	    // Termination Condition 1
	    // already calculated it
	    return resolved[curr];
	}

	if (curr == n) {
	    // Termination Condition 2
	    // reach to the end
	    return 1;
	}

	for (auto x : adj[curr]) {
	    LL nxt = x.first;
	    if (distLast[nxt] >= distLast[curr]) continue;
	    total += helper(nxt);
	    total %= M;
	}

	resolved[curr] = total;
	return total;
    }
};

